--- src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc
@@ -11,6 +11,9 @@
 #if defined(WEBRTC_POSIX)
 #include <netinet/in.h>
 #include <sys/socket.h>
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
 #ifdef OPENBSD
 #include <netinet/in_systm.h>
 #endif
