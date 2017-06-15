--- curvecp/socket_udp.c.orig	2011-02-21 01:49:34 UTC
+++ curvecp/socket_udp.c
@@ -6,6 +6,10 @@
 #include "socket.h"
 #include "blocking.h"
 
+#ifndef SOL_IP
+#define SOL_IP IPPROTO_IP  /* FreeBSD requires protocol number */
+#endif
+
 static void enable_bsd_fragmentation(int fd)
 {
 #ifdef IP_DONTFRAG
