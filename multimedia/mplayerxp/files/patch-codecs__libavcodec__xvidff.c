--- codecs/libavcodec/xvidff.c.orig	Wed Oct 18 02:39:04 2006
+++ codecs/libavcodec/xvidff.c	Mon Dec 25 01:35:12 2006
@@ -31,6 +31,10 @@
 #include "avcodec.h"
 #include "xvid_internal.h"
 
+#ifndef roundf
+#define roundf(x) (floor((x)+(float )0.5f))
+#endif
+
 /**
  * Buffer management macros.
  */
