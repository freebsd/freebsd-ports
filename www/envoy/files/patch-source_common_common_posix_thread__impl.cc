--- source/common/common/posix/thread_impl.cc.orig	2019-04-05 18:07:44 UTC
+++ source/common/common/posix/thread_impl.cc
@@ -3,6 +3,8 @@
 
 #if defined(__linux__)
 #include <sys/syscall.h>
+#elif defined(__FreeBSD__)
+#include <pthread_np.h>
 #endif
 
 namespace Envoy {
@@ -13,9 +15,9 @@ namespace {
 int64_t getCurrentThreadId() {
 #ifdef __linux__
   return static_cast<int64_t>(syscall(SYS_gettid));
-#elif defined(__APPLE__)
+#elif defined(__FreeBSD__)
   uint64_t tid;
-  pthread_threadid_np(nullptr, &tid);
+  tid = pthread_getthreadid_np();
   return tid;
 #else
 #error "Enable and test pthread id retrieval code for you arch in pthread/thread_impl.cc"
