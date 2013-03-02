--- src/libserveez/defines.h.orig	2013-01-20 23:49:50.000000000 +0900
+++ src/libserveez/defines.h	2013-02-25 14:11:54.000000000 +0900
@@ -34,6 +34,14 @@
 #include <winsock2.h>
 #endif
 
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+
+#ifdef HAVE_SYS_SOCKET_INET_H
+#include <sys/socket.h>
+#endif
+
 #ifdef HAVE_ARPA_INET_H
 #include <arpa/inet.h>
 #endif
