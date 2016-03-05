--- src/proto_http_proxy.cc.orig	2014-10-22 20:12:56 UTC
+++ src/proto_http_proxy.cc
@@ -37,6 +37,7 @@
 #include <string>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <time.h>
 
 static bool proxy_start(subnets&);
 static void proxy_open(scan_host_t *);
