--- third_party/googletest/src/googletest/include/gtest/internal/gtest-port.h.orig	2021-09-24 04:28:07 UTC
+++ third_party/googletest/src/googletest/include/gtest/internal/gtest-port.h
@@ -1644,6 +1644,8 @@ class ThreadLocal : public ThreadLocalBase {
 // MutexBase and Mutex implement mutex on pthreads-based platforms.
 class MutexBase {
  public:
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wthread-safety-analysis"
   // Acquires this mutex.
   void Lock() {
     GTEST_CHECK_POSIX_SUCCESS_(pthread_mutex_lock(&mutex_));
@@ -1660,6 +1662,7 @@ class MutexBase {
     has_owner_ = false;
     GTEST_CHECK_POSIX_SUCCESS_(pthread_mutex_unlock(&mutex_));
   }
+#pragma GCC diagnostic pop
 
   // Does nothing if the current thread holds the mutex. Otherwise, crashes
   // with high probability.
