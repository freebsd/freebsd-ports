--- mediastreamer2/src/ice.c.orig	2007-10-18 22:05:10.000000000 +0200
+++ mediastreamer2/src/ice.c	2008-03-31 10:12:57.000000000 +0200
@@ -18,9 +18,7 @@
 */
 
 #if !defined(WIN32) && !defined(_WIN32_WCE)
-#ifdef __APPLE__
 #include <sys/types.h>
-#endif
 #include <sys/socket.h>
 #include <netdb.h>
 #endif
