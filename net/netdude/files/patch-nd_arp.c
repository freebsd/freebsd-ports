--- protocols/arp/nd_arp.c.orig	Sat Oct 12 00:15:36 2002
+++ protocols/arp/nd_arp.c	Sat Oct 12 00:15:47 2002
@@ -23,6 +23,7 @@
 
 */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
