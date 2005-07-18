--- pim6sd/routesock.h.orig	Mon Jul 18 11:33:42 2005
+++ pim6sd/routesock.h	Mon Jul 18 11:33:54 2005
@@ -49,6 +49,8 @@
 #ifndef ROUTESOCK_H
 #define ROUTESOCK_H
 
+#include <sys/queue.h>
+
 struct staticrt {
 	struct sockaddr_in6 paddr;
 	u_int8 plen;
