--- third_party/webrtc/rtc_base/ipaddress.h.orig	2017-09-07 00:55:47.412632000 +0200
+++ third_party/webrtc/rtc_base/ipaddress.h	2017-09-07 00:59:49.903165000 +0200
@@ -17,6 +17,10 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #endif
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #if defined(WEBRTC_WIN)
 #include <winsock2.h>
 #include <ws2tcpip.h>
