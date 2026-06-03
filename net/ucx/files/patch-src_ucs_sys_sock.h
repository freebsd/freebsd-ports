--- src/ucs/sys/sock.h.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/sys/sock.h
@@ -8,6 +8,18 @@
 #ifndef UCS_SOCKET_H
 #define UCS_SOCKET_H
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
+#if defined(HAVE_NETINET_IN_H)
+#include <netinet/in.h>
+#endif
+
+/* inet_pton/inet_ntop */
+#if defined(HAVE_ARPA_INET_H)
+#include <arpa/inet.h>
+#endif
+
 #include <ucs/type/status.h>
 #include <ucs/config/parser.h>
 
