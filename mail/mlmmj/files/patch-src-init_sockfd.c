--- src/init_sockfd.c.orig	Thu May 20 01:19:02 2004
+++ src/init_sockfd.c	Wed Jun 16 22:12:20 2004
@@ -7,6 +7,7 @@
  */
 
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
