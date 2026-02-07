--- sessionlist.c.orig	Sun Feb  5 00:00:42 2006
+++ sessionlist.c	Sun Feb  5 00:01:48 2006
@@ -21,13 +21,13 @@
 */
 
 #include <inttypes.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <net/if.h>
 #include <netinet/if_ether.h>
 #include <netinet/tcp.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
 #include <string.h>
