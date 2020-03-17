In file included from rocksdb/utilities/backupable/backupable_db.cc:16:
rocksdb/util/channel.h:35:33: error: no matching constructor for initialization of 'std::lock_guard<std::mutex>'
    std::lock_guard<std::mutex> lk(lock_);
                                ^  ~~~~~
/usr/include/c++/v1/__mutex_base:90:14: note: candidate constructor not viable: 1st argument ('const std::mutex') would lose const qualifier
    explicit lock_guard(mutex_type& __m) _LIBCPP_THREAD_SAFETY_ANNOTATION(acquire_capability(__m))
             ^
/usr/include/c++/v1/__mutex_base:100:5: note: candidate constructor not viable: no known conversion from 'const std::mutex' to 'const std::__1::lock_guard<std::__1::mutex>' for 1st argument
    lock_guard(lock_guard const&) _LIBCPP_EQUAL_DELETE;
    ^
/usr/include/c++/v1/__mutex_base:94:5: note: candidate constructor not viable: requires 2 arguments, but 1 was provided
    lock_guard(mutex_type& __m, adopt_lock_t) _LIBCPP_THREAD_SAFETY_ANNOTATION(requires_capability(__m))
    ^
1 error generated.

https://github.com/facebook/rocksdb/commit/a796c06fef6a8e43d793f8e627db3f29e6f95964

--- cargo-crates/librocksdb-sys-6.1.3/rocksdb/util/channel.h.orig	2020-03-15 20:19:45 UTC
+++ cargo-crates/librocksdb-sys-6.1.3/rocksdb/util/channel.h
@@ -60,7 +60,7 @@ class channel {
 
  private:
   std::condition_variable cv_;
-  std::mutex lock_;
+  mutable std::mutex lock_;
   std::queue<T> buffer_;
   bool eof_;
 };
