--- io/pecan_http_server.h.orig	2009-06-16 08:23:23.000000000 +0900
+++ io/pecan_http_server.h	2009-06-28 01:29:06.320366241 +0900
@@ -20,6 +20,7 @@
 #define PECAN_HTTP_SERVER_H
 
 #include <glib-object.h>
+#include <libpurple/proxy.h>
 
 typedef struct PecanHttpServer PecanHttpServer;
 
