--- src/dyn_resolver_getdns.c.orig	2019-08-22 17:20:58 UTC
+++ src/dyn_resolver_getdns.c
@@ -33,6 +33,12 @@
 #include <sys/socket.h>
 #include <netdb.h>
 
+#ifdef __FreeBSD__
+#include <arpa/inet.h>
+#include <netinet/in.h>
+#include <resolv.h>
+#endif
+
 #include <cache/cache.h>
 #include <vsa.h>
 
