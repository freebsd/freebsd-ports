--- src/mroute.h.orig	2024-05-09 17:03:52 UTC
+++ src/mroute.h
@@ -13,7 +13,11 @@
 #include <netinet/in_var.h>
 #endif
 #include <netinet/ip.h>
+#if defined(__FreeBSD__)
 #include "queue.h"		/* Needed by netinet/ip_mroute.h on FreeBSD */
+#include <sys/callout.h>
+#include <sys/mutex.h>
+#endif
 
 #ifdef HAVE_LINUX_MROUTE_H
 #define _LINUX_IN_H             /* For Linux <= 2.6.25 */
