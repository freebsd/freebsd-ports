--- src/gskipv4.c.orig	2006-05-17 18:39:35 UTC
+++ src/gskipv4.c
@@ -1,7 +1,9 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include "gskipv4.h"
 
 /* Standard ipv4 addresses in guint8[4] format. */
