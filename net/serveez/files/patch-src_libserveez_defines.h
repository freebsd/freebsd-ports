--- src/libserveez/defines.h.orig	2021-12-11 09:07:37 UTC
+++ src/libserveez/defines.h
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
