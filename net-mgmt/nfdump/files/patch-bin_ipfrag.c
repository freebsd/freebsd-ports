--- bin/ipfrag.c.orig	2019-09-20 22:19:55.060019000 +0200
+++ bin/ipfrag.c	2019-09-20 22:20:13.307477000 +0200
@@ -37,6 +37,7 @@
 #include <string.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #ifdef HAVE_NETINET_IN_SYSTM_H
 #include <netinet/in_systm.h>
 #endif
