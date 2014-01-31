--- curvecp/socket_udp.c.orig	2014-01-29 15:34:07.000000000 -0800
+++ curvecp/socket_udp.c	2014-01-29 15:34:12.000000000 -0800
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
