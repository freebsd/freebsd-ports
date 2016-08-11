--- resolve.c.orig	2016-02-19 06:35:50.592222000 -0800
+++ resolve.c	2016-04-21 19:32:37.383666000 -0700
@@ -5,7 +5,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#define _KERNEL
 #include <netinet/in.h>
+#undef _KERNEL
 #include <arpa/inet.h>
 #include <sys/socket.h>
 #include <netdb.h>
