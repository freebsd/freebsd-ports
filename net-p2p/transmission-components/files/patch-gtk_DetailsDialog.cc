--- gtk/DetailsDialog.cc.orig	2023-07-05 18:51:40 UTC
+++ gtk/DetailsDialog.cc
@@ -68,6 +68,7 @@
 #include <ws2tcpip.h>
 #else
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif
 
 using namespace std::literals;
