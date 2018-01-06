--- src/3rdparty/chromium/third_party/webrtc/base/ifaddrs_converter.h.orig	2017-01-26 00:50:17 UTC
+++ src/3rdparty/chromium/third_party/webrtc/base/ifaddrs_converter.h
@@ -14,6 +14,8 @@
 #if defined(WEBRTC_ANDROID)
 #include "webrtc/base/ifaddrs-android.h"
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 #endif  // WEBRTC_ANDROID
 
