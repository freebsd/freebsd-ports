--- libvo/yuv2rgb.c.orig	Wed Feb 23 05:08:14 2005
+++ libvo/yuv2rgb.c	Wed Feb 23 05:09:12 2005
@@ -71,7 +71,7 @@
 void yuv2rgb_init (int bpp, int mode) 
 {
     yuv2rgb = NULL;
-#if defined(ARCH_X86) || defined(ARCH_X86_64)
+#if defined(ARCH_X86)
     if ((yuv2rgb == NULL) && (vo_mm_accel & MM_ACCEL_X86_MMXEXT)) {
 	yuv2rgb = yuv2rgb_init_mmxext (bpp, mode);
 	if (yuv2rgb != NULL)
