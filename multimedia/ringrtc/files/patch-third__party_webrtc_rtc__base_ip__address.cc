--- src/webrtc/src/rtc_base/ip_address.cc.orig	2022-05-19 14:06:27 UTC
+++ src/webrtc/src/rtc_base/ip_address.cc
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
