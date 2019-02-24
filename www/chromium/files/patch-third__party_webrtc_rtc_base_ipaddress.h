--- third_party/webrtc/rtc_base/ipaddress.h.orig	2019-01-30 02:20:38.000000000 +0100
+++ third_party/webrtc/rtc_base/ipaddress.h	2019-02-01 23:40:04.663435000 +0100
@@ -17,6 +17,10 @@
 #include <netinet/in.h>
 #include <sys/socket.h>
 #endif
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #if defined(WEBRTC_WIN)
 #include <winsock2.h>
 #include <ws2tcpip.h>
