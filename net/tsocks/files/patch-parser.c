--- parser.c.orig	Wed Oct  8 01:43:48 2003
+++ parser.c	Wed Oct  8 01:43:58 2003
@@ -4,6 +4,7 @@
 
 */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
