--- protocols/ether/nd_ether.c.orig	Sat Oct 12 00:18:53 2002
+++ protocols/ether/nd_ether.c	Sat Oct 12 00:19:07 2002
@@ -23,6 +23,7 @@
 
 */
 
+#include <sys/types.h>
 #include <net/ethernet.h>
 
 #include <netdude/nd_debug.h>
