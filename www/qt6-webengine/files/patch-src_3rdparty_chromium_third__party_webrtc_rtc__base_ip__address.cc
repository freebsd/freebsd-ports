--- src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc
@@ -14,7 +14,8 @@
 #include <cstring>
 #include <string>
 #if defined(WEBRTC_POSIX)
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #ifndef __native_client__
