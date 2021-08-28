--- plugins/output_rtsp/output_rtsp.c.orig	2021-08-17 00:57:41 UTC
+++ plugins/output_rtsp/output_rtsp.c
@@ -38,6 +38,7 @@
 #include <errno.h>
 #include <signal.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <resolv.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
