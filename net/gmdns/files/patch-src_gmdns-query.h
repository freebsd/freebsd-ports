--- src/gmdns-query.h.orig	Sat Jun  5 23:08:23 2004
+++ src/gmdns-query.h	Sat Jun  5 23:09:06 2004
@@ -23,7 +23,10 @@
 
 #include <glib-object.h>
 #include <gmdns.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 #define GMDNS_TYPE_QUERY			(gmdns_query_get_type ())
 #define GMDNS_QUERY(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GMDNS_TYPE_QUERY, GmDNSQuery))
