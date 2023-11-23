--- src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc.orig	2022-05-19 14:06:27 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc
@@ -13,7 +13,8 @@
 #include <sys/socket.h>
 
 #include "absl/strings/string_view.h"
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #ifndef __native_client__
