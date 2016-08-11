--- v8/src/base/platform/platform-posix.cc.orig	2016-05-11 19:04:08 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -55,6 +55,14 @@
 #include <sys/prctl.h>  // NOLINT, for prctl
 #endif
 
+#if V8_OS_FREEBSD && !defined(__DragonFly__)
+#include <sys/thr.h>   // for thr_self
+#endif
+
+#if V8_OS_NETBSD
+#include <lwp.h>       // for _lwp_self
+#endif
+
 #if !defined(V8_OS_NACL) && !defined(_AIX)
 #include <sys/syscall.h>
 #endif
@@ -329,6 +337,12 @@ int OS::GetCurrentThreadId() {
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_DRAGONFLYBSD || defined(__DragonFly__)
+  return static_cast<int>(lwp_gettid());
+#elif V8_OS_FREEBSD
+  return static_cast<int>(pthread_getthreadid_np());
+#elif V8_OS_NETBSD
+  return static_cast<int>(_lwp_self());
 #elif V8_OS_AIX
   return static_cast<int>(thread_self());
 #elif V8_OS_SOLARIS
