--- third_party/libjingle/source/talk/base/ipaddress.h.orig	2012-01-30 22:44:57.000000000 +0200
+++ third_party/libjingle/source/talk/base/ipaddress.h	2012-01-30 22:47:28.000000000 +0200
@@ -33,6 +33,9 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #endif
+#ifdef BSD
+#include <sys/socket.h>
+#endif
 #ifdef WIN32
 #include <winsock2.h>
 #include <ws2tcpip.h>
