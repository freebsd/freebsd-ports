--- src/i965_decoder_utils.c.orig	2013-06-26 05:14:51.000000000 +0200
+++ src/i965_decoder_utils.c	2013-06-27 16:06:27.234183751 +0200
@@ -23,7 +23,11 @@
 
 #include "sysdeps.h"
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 
 #include "intel_batchbuffer.h"
 #include "i965_drv_video.h"
