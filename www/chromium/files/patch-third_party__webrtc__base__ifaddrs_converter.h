--- third_party/webrtc/base/ifaddrs_converter.h.orig	2016-04-02 20:56:46.173477407 +0200
+++ third_party/webrtc/base/ifaddrs_converter.h	2016-04-02 20:57:11.910537987 +0200
@@ -14,6 +14,8 @@
 #if defined(WEBRTC_ANDROID)
 #include "webrtc/base/ifaddrs-android.h"
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 #endif  // WEBRTC_ANDROID
 
