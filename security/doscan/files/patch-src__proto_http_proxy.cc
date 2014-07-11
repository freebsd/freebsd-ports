--- ./src/proto_http_proxy.cc.orig	2014-07-08 13:39:24.466003083 +0200
+++ ./src/proto_http_proxy.cc	2014-07-08 13:40:02.286093067 +0200
@@ -36,6 +36,7 @@
 #include <string>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <time.h>
 
 static bool proxy_start(subnets&);
 static void proxy_open(scan_host_t *);
