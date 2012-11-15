--- src/i965_decoder_utils.c.orig	2012-11-09 02:44:47.000000000 +0100
+++ src/i965_decoder_utils.c	2012-11-14 10:45:13.909019239 +0100
@@ -22,7 +22,11 @@
  */
 
 #include "sysdeps.h"
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #include "intel_batchbuffer.h"
 #include "i965_decoder_utils.h"
 #include "i965_drv_video.h"
