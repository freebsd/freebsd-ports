--- plugins/netutils.h.orig	Sat Aug  9 01:05:17 2003
+++ plugins/netutils.h	Sat Nov 27 13:10:26 2004
@@ -47,7 +47,7 @@
 
 int my_tcp_connect (const char *address, int port, int *sd);
 int my_udp_connect (const char *address, int port, int *sd);
-int my_connect (const char *address, int port, int *sd, int proto);
+int nagios_my_connect (const char *address, int port, int *sd, int proto);
 
 int is_host (const char *);
 int is_addr (const char *);
