--- src/input/librtsp/rtsp.c.orig	Sun Jan  5 19:30:50 2003
+++ src/input/librtsp/rtsp.c	Sun Jan  5 19:31:21 2003
@@ -23,6 +23,7 @@
  * *not* RFC 2326 compilant yet.
  */
 
+#include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <assert.h>
