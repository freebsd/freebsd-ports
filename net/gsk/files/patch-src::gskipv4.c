--- src/gskipv4.c.orig	Tue Dec  7 06:53:22 2004
+++ src/gskipv4.c	Sun Jan 30 23:55:09 2005
@@ -1,5 +1,7 @@
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include "gskipv4.h"
 
