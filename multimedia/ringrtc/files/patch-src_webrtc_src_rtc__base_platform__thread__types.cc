--- src/webrtc/src/rtc_base/platform_thread_types.cc.orig	2021-01-28 23:16:17 UTC
+++ src/webrtc/src/rtc_base/platform_thread_types.cc
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
 
@@ -44,6 +48,8 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(__FreeBSD__)
+  return pthread_getthreadid_np();
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #elif defined(__EMSCRIPTEN__)
@@ -74,6 +80,7 @@ void SetCurrentThreadName(const char* name) {
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(__FreeBSD__)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -120,6 +127,7 @@ void SetCurrentThreadName(const char* name) {
   zx_status_t status = zx_object_set_property(zx_thread_self(), ZX_PROP_NAME,
                                               name, strlen(name));
   RTC_DCHECK_EQ(status, ZX_OK);
+#endif
 #endif
 }
 
