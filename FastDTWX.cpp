// FastDTWX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "DTW.h"
#include "FastDTW.h"
#include "EuclideanDistance.h"
#include <iostream>

using namespace fastdtw;

double sample1[]{1,2,3,4,5,6,7,8};
double sample2[]{9,8,7,6,5,4,3,2,1,0};
int sampleLength = 8;

void testDTW()
{
    TimeSeries<double, 1> tsI;
    for (int i = 0; i < sampleLength; ++i) {
        tsI.addLast(i, TimeSeriesPoint<double, 1>(sample1 + i));
    }

    TimeSeries<double, 1> tsJ;
    for (int i = 0; i < sampleLength; ++i)
    {
        tsJ.addLast(i, TimeSeriesPoint<double, 1>(sample2 + i));
    }

    TimeWarpInfo<double> info = STRI::getWarpInfoBetween(tsI, tsJ, EuclideanDistance());
    printf("Warp Distance by DTW:%lf\n", info.getDistance());
    info.getPath()->print(std::cout);
}

void testFastDTW()
{
    TimeSeries<double, 1> tsI;
    for (int i = 0; i < sampleLength; ++i) {
        tsI.addLast(i, TimeSeriesPoint<double, 1>(sample1 + i));
    }

    TimeSeries<double, 1> tsJ;
    for (int i = 0; i < sampleLength; ++i)
    {
        tsJ.addLast(i, TimeSeriesPoint<double, 1>(sample2 + i));
    }

    TimeWarpInfo<double> info = FAST::getWarpInfoBetween(tsI, tsJ, EuclideanDistance());
    printf("Warp Distance by DTW:%lf\n", info.getDistance());
    info.getPath()->print(std::cout);
}



int main()
{
    testDTW();
    testFastDTW();

    return 0;
}
