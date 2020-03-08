--- base/threading/platform_thread_posix.cc.orig	2020-03-03 18:53:47 UTC
+++ base/threading/platform_thread_posix.cc
@@ -32,6 +32,10 @@
 #include <sys/syscall.h>
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/thr.h>
+#endif
+
 #if defined(OS_FUCHSIA)
 #include <zircon/process.h>
 #else
@@ -66,7 +70,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::ThreadRestrictions::SetSingletonAllowed(false);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
     // Threads on linux/android may inherit their priority from the thread
     // where they were created. This explicitly sets the priority of all new
     // threads.
@@ -188,6 +192,10 @@ PlatformThreadId PlatformThread::CurrentId() {
   return g_thread_id;
 #elif defined(OS_ANDROID)
   return gettid();
+#elif defined(OS_FREEBSD)
+  long x;
+  thr_self(&x);
+  return x;
 #elif defined(OS_FUCHSIA)
   return zx_thread_self();
 #elif defined(OS_SOLARIS) || defined(OS_QNX)
