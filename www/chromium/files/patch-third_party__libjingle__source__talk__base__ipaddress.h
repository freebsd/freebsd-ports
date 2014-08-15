--- ./third_party/libjingle/source/talk/base/ipaddress.h.orig	2014-08-12 21:03:39.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/ipaddress.h	2014-08-13 09:56:58.000000000 +0200
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
