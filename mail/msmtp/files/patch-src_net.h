--- src/net.h.orig	Sun Apr 10 17:00:50 2005
+++ src/net.h	Sun Apr 10 17:01:02 2005
@@ -26,7 +26,7 @@
 
 #ifndef NET_H
 #define NET_H
-
+#include <unistd.h>
 
 /* All 'errstr' arguments must point to buffers that are at least
  * 'errstr_bufsize' characters long.
