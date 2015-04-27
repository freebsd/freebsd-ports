--- v8/src/base/platform/platform-posix.cc.orig	2015-04-19 17:42:27.000000000 +0200
+++ v8/src/base/platform/platform-posix.cc	2015-04-19 17:46:17.000000000 +0200
@@ -55,6 +55,15 @@
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
 #if !defined(V8_OS_NACL) && !defined(_AIX)
 #include <sys/syscall.h>
 #endif
@@ -271,6 +280,18 @@
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
 #elif V8_OS_AIX
   return static_cast<int>(thread_self());
 #elif V8_OS_SOLARIS
