--- v8/src/base/platform/platform-posix.cc.orig	2015-01-27 03:22:59.000000000 +0100
+++ v8/src/base/platform/platform-posix.cc	2015-02-06 18:41:53.881294389 +0100
@@ -54,6 +54,15 @@
 #include <sys/prctl.h>  // NOLINT, for prctl
 #endif
 
+#if V8_OS_FREEBSD && !defined(__DragonFly__)
+#include <sys/param.h> // for __FreeBSD_version
+#include <sys/thr.h>   // for thr_self
+#endif
+
+#if V8_OS_NETBSD
+#include <lwp.h>       // for _lwp_self
+#endif
+
 #if !V8_OS_NACL
 #include <sys/syscall.h>
 #endif
@@ -259,6 +268,18 @@ int OS::GetCurrentThreadId() {
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_DRAGONFLYBSD || defined(__DragonFly__)
+  return static_cast<int>(lwp_gettid());
+#elif V8_OS_FREEBSD
+#  if __FreeBSD_version < 900031
+  long lwpid;
+  thr_self(&lwpid);
+  return static_cast<int>(lwpid);
+#  else
+  return static_cast<int>(pthread_getthreadid_np());
+#  endif
+#elif V8_OS_NETBSD
+  return static_cast<int>(_lwp_self());
 #else
   return static_cast<int>(pthread_self());
 #endif
