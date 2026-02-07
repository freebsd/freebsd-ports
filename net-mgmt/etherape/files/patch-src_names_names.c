--- src/names/names.c.orig	2017-03-18 16:11:42 UTC
+++ src/names/names.c
@@ -19,7 +19,18 @@
 #include <config.h>
 #endif
 
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+#ifdef HAVE_NETINET_IN_H
 #include <netinet/in.h>
+#endif
+#ifdef HAVE_ARPA_INET_H
+#include <arpa/inet.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
