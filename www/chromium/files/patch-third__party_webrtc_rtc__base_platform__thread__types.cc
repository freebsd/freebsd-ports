--- third_party/webrtc/rtc_base/platform_thread_types.cc.orig	2021-04-14 18:43:12 UTC
+++ third_party/webrtc/rtc_base/platform_thread_types.cc
@@ -11,7 +11,11 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#else
+#include <pthread_np.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
@@ -37,6 +41,8 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(__FreeBSD__)
+  return pthread_getthreadid_np();
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
@@ -67,6 +73,7 @@ bool IsThreadRefEqual(const PlatformThreadRef& a, cons
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(__FreeBSD__)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -109,6 +116,7 @@ void SetCurrentThreadName(const char* name) {
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#endif
 #endif
 }
 
