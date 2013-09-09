--- ./hupnp/src/socket/hmulticast_socket.cpp.orig	2011-03-28 00:42:32.000000000 +0300
+++ ./hupnp/src/socket/hmulticast_socket.cpp	2013-09-10 00:35:26.000000000 +0300
@@ -26,7 +26,10 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <sys/types.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 #include <QtNetwork/QNetworkProxy>
