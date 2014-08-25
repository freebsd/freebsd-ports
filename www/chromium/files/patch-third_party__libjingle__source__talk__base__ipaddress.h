--- ./third_party/libjingle/source/talk/base/ipaddress.h.orig	2014-08-20 21:03:47.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/ipaddress.h	2014-08-22 15:06:26.000000000 +0200
@@ -34,6 +34,9 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #endif
+#ifdef BSD
+#include <sys/socket.h>
+#endif
 #ifdef WIN32
 #include <winsock2.h>
 #include <ws2tcpip.h>
