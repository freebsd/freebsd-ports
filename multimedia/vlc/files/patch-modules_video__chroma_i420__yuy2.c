--- modules/video_chroma/i420_yuy2.c.orig	2019-09-12 13:09:52 UTC
+++ modules/video_chroma/i420_yuy2.c
@@ -37,7 +37,9 @@
 #include <vlc_cpu.h>
 
 #if defined (MODULE_NAME_IS_i420_yuy2_altivec) && defined(HAVE_ALTIVEC_H)
+#   undef bool
 #   include <altivec.h>
+#   define bool _Bool
 #endif
 
 #include "i420_yuy2.h"
