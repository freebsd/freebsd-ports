--- src/gskipv4.c.orig	2006-05-18 03:39:35.000000000 +0900
+++ src/gskipv4.c	2009-04-08 00:18:45.000000000 +0900
@@ -1,7 +1,9 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include "gskipv4.h"
 
 /* Standard ipv4 addresses in guint8[4] format. */
