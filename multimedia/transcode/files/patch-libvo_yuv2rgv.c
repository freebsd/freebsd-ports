--- libvo/yuv2rgb.c.orig	Sun May  8 16:57:56 2005
+++ libvo/yuv2rgb.c	Sun May  8 16:58:18 2005
@@ -72,7 +72,7 @@
 {
     yuv2rgb = NULL;
 #ifdef HAVE_MMX
-# if defined(ARCH_X86) || defined(ARCH_X86_64)
+# if defined(ARCH_X86)
     if ((yuv2rgb == NULL) && (vo_mm_accel & MM_ACCEL_X86_MMXEXT)) {
 	yuv2rgb = yuv2rgb_init_mmxext (bpp, mode);
 	if (yuv2rgb != NULL)
