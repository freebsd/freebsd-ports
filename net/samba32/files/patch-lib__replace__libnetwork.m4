--- lib/replace/libreplace_network.m4.orig	2009-02-20 17:12:18.000000000 +0000
+++ lib/replace/libreplace_network.m4	2009-02-20 17:14:31.000000000 +0000
@@ -353,6 +353,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netdb.h>
+#include <netinet/in.h>
 		],
 		[
 struct sockaddr_storage sa_store;
