--- src/input/libreal/sdpplin.c.orig	Sun Jan  5 19:28:03 2003
+++ src/input/libreal/sdpplin.c	Sun Jan  5 19:29:02 2003
@@ -22,7 +22,8 @@
  * sdp/sdpplin parser.
  *
  */
- 
+
+#include <sys/types.h> 
 #include "rmff.h"
 #include "rtsp.h"
 #include "sdpplin.h"
