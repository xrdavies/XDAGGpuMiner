#pragma once

#include "XTime.h"
#include "XHash.h"
#include "XBlock.h"
#include <mutex>

struct cheatcoin_pool_task
{
    cheatcoin_field task[2], lastfield, minhash, nonce;
    cheatcoin_time_t main_time;
    SHA256_CTX ctx;
};

class XTaskProcessor;

class XTaskWrapper
{
    friend class XTaskProcessor;
private:
    cheatcoin_pool_task _task;
    std::mutex _shareMutex;
    uint64_t _taskIndex;
    bool _isShareFound;
public:
    XTaskWrapper();
    ~XTaskWrapper();

    cheatcoin_pool_task* GetTask() { return &_task; }
    void SetShare(cheatcoin_hash_t last, cheatcoin_hash_t hash);
    uint64_t GetIndex() { return _taskIndex; }
    bool IsShareFound() { return _isShareFound; }

    void DumpTask();
};
