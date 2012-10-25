--- src/i965_decoder_utils.c.orig	2012-08-14 17:08:16.000000000 +0200
+++ src/i965_decoder_utils.c	2012-10-10 17:25:22.358503055 +0200
@@ -24,7 +24,11 @@
 #include <assert.h>
 #include <stddef.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #include "intel_batchbuffer.h"
 #include "i965_decoder_utils.h"
 #include "i965_drv_video.h"
