--- src/names.c.orig	2014-02-02 11:30:03 UTC
+++ src/names.c
@@ -21,7 +21,18 @@
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
