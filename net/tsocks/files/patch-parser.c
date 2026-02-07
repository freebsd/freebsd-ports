--- parser.c.orig	2002-03-13 12:34:22 UTC
+++ parser.c
@@ -4,6 +4,7 @@
 
 */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
