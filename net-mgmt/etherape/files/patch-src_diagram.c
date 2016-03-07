--- src/diagram.c.orig	2016-01-25 20:19:16 UTC
+++ src/diagram.c
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
+#include <netinet/in.h>
+#endif
+#ifdef HAVE_ARPA_INET_H
 #include <arpa/inet.h>
+#endif
 
 #include <gnome.h>
 #include <regex.h>
