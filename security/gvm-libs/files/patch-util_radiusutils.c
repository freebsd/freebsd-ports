--- util/radiusutils.c	2020-12-31 02:24:20.387082000 -0500
+++ util/radiusutils.c	2020-12-31 02:27:54.965720000 -0500
@@ -24,6 +24,9 @@
 
 #ifdef ENABLE_RADIUS_AUTH
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h> /* for inet_pton */
 
 #if defined(RADIUS_AUTH_FREERADIUS)
