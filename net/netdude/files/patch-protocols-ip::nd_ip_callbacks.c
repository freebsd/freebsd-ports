--- protocols/ip/nd_ip_callbacks.c.orig	Sun Oct 13 21:35:01 2002
+++ protocols/ip/nd_ip_callbacks.c	Sun Oct 13 21:35:31 2002
@@ -26,6 +26,7 @@
 #ifdef LINUX
 #define __FAVOR_BSD
 #endif
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
