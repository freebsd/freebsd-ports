--- lanserv/extcmd.c.orig	2018-07-30 08:08:12 UTC
+++ lanserv/extcmd.c
@@ -53,16 +53,11 @@
  *      written permission.
  */
 #include <config.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
-#ifdef HAVE_NETINET_ETHER_H
-#include <netinet/ether.h>
-#elif defined(HAVE_SYS_ETHERNET_H)
-#include <sys/ethernet.h>
-#else
-#error "either netinet/ether.h or sys/ethernet.h must exist."
-#endif
+#include <net/ethernet.h>
 #include <ctype.h>
 #include <string.h>
 #include <errno.h>
