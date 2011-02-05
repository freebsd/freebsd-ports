--- ./hupnp/src/hupnp_core/socket/hmulticast_socket.cpp.orig	2010-12-29 14:08:26.000000000 +1000
+++ ./hupnp/src/hupnp_core/socket/hmulticast_socket.cpp	2010-12-29 14:10:00.000000000 +1000
@@ -27,6 +27,8 @@
 #include <ws2tcpip.h>
 #else
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #endif
 
 #include <QtNetwork/QNetworkProxy>
