--- codecs/video/mpeg3/motion_comp.c.orig	Tue Oct 28 08:53:27 2003
+++ codecs/video/mpeg3/motion_comp.c	Tue Oct 28 08:55:16 2003
@@ -66,7 +66,7 @@
 // mc function template
 
 #define MC_FUNC(op,xy)						\
-static void motion_comp_##op####xy##_16x16_c (uint8_t * dest,	\
+static void motion_comp_##op##xy##_16x16_c (uint8_t * dest,	\
 					      uint8_t * ref,	\
 					      int stride,	\
 					      int height)	\
@@ -92,7 +92,7 @@
 	dest += stride;						\
     } while (--height);						\
 }								\
-static void motion_comp_##op####xy##_8x8_c (uint8_t * dest,	\
+static void motion_comp_##op##xy##_8x8_c (uint8_t * dest,	\
 					    uint8_t * ref,	\
 					    int stride,		\
 					    int height)		\
