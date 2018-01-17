--- src/3rdparty/chromium/third_party/webrtc/base/ipaddress.h.orig	2017-01-26 00:50:17 UTC
+++ src/3rdparty/chromium/third_party/webrtc/base/ipaddress.h
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
