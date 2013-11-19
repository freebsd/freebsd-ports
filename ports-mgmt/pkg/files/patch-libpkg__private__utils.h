--- ./libpkg/private/utils.h.orig	2013-07-06 05:48:19.000000000 -0500
+++ ./libpkg/private/utils.h	2013-11-19 11:13:45.354131958 -0600
@@ -60,6 +60,7 @@
 	unsigned int priority;
 	unsigned int weight;
 	unsigned int port;
+	unsigned int finalweight;
 	char host[MAXHOSTNAMELEN];
 	struct dns_srvinfo *next;
 };
