--- third_party/webrtc/base/ifaddrs_converter.h.orig	2016-05-11 19:04:03 UTC
+++ third_party/webrtc/base/ifaddrs_converter.h
@@ -14,6 +14,8 @@
 #if defined(WEBRTC_ANDROID)
 #include "webrtc/base/ifaddrs-android.h"
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 #endif  // WEBRTC_ANDROID
 
