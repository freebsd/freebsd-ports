--- ./hupnp/src/socket/hmulticast_socket.cpp.orig	2011-03-28 00:42:32.000000000 +1100
+++ ./hupnp/src/socket/hmulticast_socket.cpp	2011-08-08 11:59:59.868629425 +1100
@@ -27,6 +27,8 @@
 #include <ws2tcpip.h>
 #else
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 #include <QtNetwork/QNetworkProxy>
