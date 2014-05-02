--- ./third_party/libjingle/source/talk/base/ipaddress.h.orig	2014-04-24 22:36:53.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/ipaddress.h	2014-04-24 23:23:48.000000000 +0200
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
