--- testserver.c.orig	Tue May 22 05:04:28 2001
+++ testserver.c	Sun May 27 18:47:01 2001
@@ -19,6 +19,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 
 
