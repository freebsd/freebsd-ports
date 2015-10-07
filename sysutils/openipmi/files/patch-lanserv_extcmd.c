--- lanserv/extcmd.c.orig	2015-07-30 03:31:16 UTC
+++ lanserv/extcmd.c
@@ -52,10 +52,11 @@
  *      products derived from this software without specific prior
  *      written permission.
  */
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#include <netinet/ether.h>
+#include <net/ethernet.h>
 #include <ctype.h>
 #include <string.h>
 #include <errno.h>
