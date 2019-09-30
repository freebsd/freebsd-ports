--- modules/video_filter/deinterlace/merge.c.orig	2019-09-12 13:33:43 UTC
+++ modules/video_filter/deinterlace/merge.c
@@ -39,7 +39,9 @@
 #endif
 
 #ifdef HAVE_ALTIVEC_H
+#   undef bool
 #   include <altivec.h>
+#   define bool _Bool
 #endif
 
 /*****************************************************************************
