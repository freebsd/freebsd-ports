--- src/i965_decoder_utils.c.orig	2014-12-24 00:59:48 UTC
+++ src/i965_decoder_utils.c
@@ -23,7 +23,11 @@
 
 #include "sysdeps.h"
 #include <limits.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 
 #include "intel_batchbuffer.h"
 #include "intel_media.h"
