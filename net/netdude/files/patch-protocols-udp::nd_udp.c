--- protocols/udp/nd_udp.c.orig	Sun Oct 13 21:47:40 2002
+++ protocols/udp/nd_udp.c	Sun Oct 13 21:49:50 2002
@@ -26,6 +26,10 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
+#include <netinet/ip_var.h>
 #include <netinet/ip.h>
 
 #include <netdude/nd_debug.h>
