--- nasl/capture_packet.c.orig	2015-08-03 10:14:31 UTC
+++ nasl/capture_packet.c
@@ -17,6 +17,7 @@
  *
  */
 
+#include <sys/socket.h>         /* for AF_INET6 */
 #include <arpa/inet.h>          /* for inet_ntoa */
 #include <string.h>             /* for bcopy */
 #include <glib.h>               /* for gfree */
