--- v8/src/base/platform/platform-posix.cc.orig	2017-04-19 19:07:57 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -27,6 +27,10 @@
 #include <sys/sysctl.h>  // NOLINT, for sysctl
 #endif
 
+#if V8_OS_NETBSD
+#include <lwp.h>       // for _lwp_self
+#endif
+
 #undef MAP_TYPE
 
 #if defined(ANDROID) && !defined(V8_ANDROID_LOG_STDOUT)
@@ -352,6 +356,12 @@ int OS::GetCurrentThreadId() {
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
