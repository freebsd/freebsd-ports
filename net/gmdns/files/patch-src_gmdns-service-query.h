--- src/gmdns-service-query.h.orig	Sun Jun  6 01:16:02 2004
+++ src/gmdns-service-query.h	Sun Jun  6 01:16:25 2004
@@ -23,7 +23,10 @@
 
 #include <glib-object.h>
 #include <gmdns.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 #define GMDNS_TYPE_SERVICE_QUERY			(gmdns_service_query_get_type ())
 #define GMDNS_SERVICE_QUERY(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GMDNS_TYPE_SERVICE_QUERY, GmDNSServiceQuery))
