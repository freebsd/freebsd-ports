--- protocols/snap/nd_snap.c.orig	Sun Oct 13 21:40:25 2002
+++ protocols/snap/nd_snap.c	Sun Oct 13 21:41:10 2002
@@ -26,6 +26,7 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <net/ethernet.h>
 
 #include <netdude/nd_debug.h>
