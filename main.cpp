#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        if (time.empty()) return 0;
        vector<int> dur(60);
        for (auto &i : time) {
            i = i % 60;
            ++dur[i];
        }
        // 5 songs with 30s ==> 5 * 4 / 2 = 10
        int count = 0;
        if (dur[0] > 1) {
            count += dur[0] * (dur[0] - 1) / 2;
        }
        if (dur[30] > 1) {
            count += dur[30] * (dur[30] - 1) / 2;
        }
        for (int i = 1; i < 30; ++i) {
            count += dur[i] * dur[60 - i];
        }
        return count;
    }
};

void test1() {
    vector<int> v1{30, 20, 150, 100, 40};

    cout << "3 ? " << Solution().numPairsDivisibleBy60(v1) << endl;

    // [418,204,77,278,239,457,284,263,372,279,476,416,360,18]
    vector<int> v2{3418,204,77,278,239,457,284,263,372,279,476,416,360,18};

    cout << "1 ? " << Solution().numPairsDivisibleBy60(v2) << endl;
}

void test2() {

}

void test3() {

}