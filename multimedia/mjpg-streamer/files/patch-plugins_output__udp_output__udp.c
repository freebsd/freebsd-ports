--- plugins/output_udp/output_udp.c.orig	2021-08-17 01:14:40 UTC
+++ plugins/output_udp/output_udp.c
@@ -38,6 +38,7 @@
 #include <errno.h>
 #include <signal.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <resolv.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
