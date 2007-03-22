--- mediastreamer2/src/ice.c.orig	Fri Jan  5 06:42:59 2007
+++ mediastreamer2/src/ice.c	Sun Feb 25 03:37:44 2007
@@ -18,6 +18,7 @@
 */
 
 #if !defined(WIN32) && !defined(_WIN32_WCE)
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #endif
