--- src/constants.c.orig	Thu Jan  9 03:24:04 2003
+++ src/constants.c	Thu Jan  9 03:26:25 2003
@@ -25,6 +25,7 @@
 #endif
 
 #ifdef HAVE_NETINET_TCP_H
+#include <sys/types.h>
 #include <netinet/tcp.h>
 #endif
 
