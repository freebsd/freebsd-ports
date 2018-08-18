--- third_party/webrtc/rtc_base/platform_thread.cc.orig	2018-06-13 00:12:10.000000000 +0200
+++ third_party/webrtc/rtc_base/platform_thread.cc	2018-07-19 21:16:37.263549000 +0200
@@ -15,7 +15,9 @@
 #include "rtc_base/timeutils.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__FreeBSD__)
 #include <sys/prctl.h>
+#endif
 #include <sys/syscall.h>
 #endif
 
