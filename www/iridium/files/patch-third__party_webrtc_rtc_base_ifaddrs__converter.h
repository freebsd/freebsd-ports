--- third_party/webrtc/rtc_base/ifaddrs_converter.h.orig	2017-09-07 00:50:44.713781000 +0200
+++ third_party/webrtc/rtc_base/ifaddrs_converter.h	2017-09-07 00:51:25.775459000 +0200
@@ -14,6 +14,8 @@
 #if defined(WEBRTC_ANDROID)
 #include "webrtc/rtc_base/ifaddrs-android.h"
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 #endif  // WEBRTC_ANDROID
 
