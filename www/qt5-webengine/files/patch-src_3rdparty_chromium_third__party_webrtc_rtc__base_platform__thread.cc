--- src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/platform_thread.cc
@@ -15,7 +15,9 @@
 #include "rtc_base/timeutils.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
