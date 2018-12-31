--- Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/platform_thread_types.cc.orig	2018-11-23 01:03:16 UTC
+++ Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/platform_thread_types.cc
@@ -11,9 +11,13 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
+#ifdef __FreeBSD__
+#include <sys/thr.h>
+#else
 #include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
+#endif
 
 namespace rtc {
 
@@ -27,6 +31,10 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(__FreeBSD__)
+  long tid;
+  thr_self(&tid);
+  return tid;
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #else
