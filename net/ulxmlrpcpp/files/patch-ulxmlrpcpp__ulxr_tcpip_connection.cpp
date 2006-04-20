--- ulxmlrpcpp/ulxr_tcpip_connection.cpp.orig	Sun Apr 16 04:15:21 2006
+++ ulxmlrpcpp/ulxr_tcpip_connection.cpp	Mon Apr 17 01:39:52 2006
@@ -45,6 +45,8 @@
 #endif
 
 #ifdef __unix__
+#include <sys/time.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/tcp.h>
 #endif
