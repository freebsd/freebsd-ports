--- src/libffmpeg/libavcodec/vorbis.c.orig	Thu Sep 28 13:27:16 2006
+++ src/libffmpeg/libavcodec/vorbis.c	Thu Sep 28 13:27:41 2006
@@ -29,6 +29,8 @@
 #include "dsputil.h"
 
 #include "vorbis.h"
+#include "xine_internal.h"
+
 
 #define V_NB_BITS 8
 #define V_NB_BITS2 11
