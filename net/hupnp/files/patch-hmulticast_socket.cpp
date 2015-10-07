--- hupnp/src/socket/hmulticast_socket.cpp.orig	2011-03-27 20:42:32 UTC
+++ hupnp/src/socket/hmulticast_socket.cpp
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
