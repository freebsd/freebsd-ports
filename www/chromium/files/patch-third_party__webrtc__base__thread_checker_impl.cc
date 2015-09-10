--- third_party/webrtc/base/thread_checker_impl.cc.orig	2015-04-19 18:30:59.000000000 +0200
+++ third_party/webrtc/base/thread_checker_impl.cc	2015-04-19 18:51:43.000000000 +0200
@@ -14,10 +14,15 @@
 
 #include "webrtc/base/checks.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(__FreeBSD__)
 #include <sys/syscall.h>
 #endif
 
+#if defined(WEBRTC_BSD)
+#include <pthread_np.h>
+#include <sys/thr.h>
+#endif
+
 namespace rtc {
 
 PlatformThreadId CurrentThreadId() {
@@ -27,6 +32,8 @@
 #elif defined(WEBRTC_POSIX)
 #if defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   ret = pthread_mach_thread_np(pthread_self());
+#elif defined(WEBRTC_BSD)
+  ret = static_cast<int>(pthread_getthreadid_np());
 #elif defined(WEBRTC_LINUX)
   ret =  syscall(__NR_gettid);
 #elif defined(WEBRTC_ANDROID)
