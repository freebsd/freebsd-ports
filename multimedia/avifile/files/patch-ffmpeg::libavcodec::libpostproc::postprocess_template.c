--- ffmpeg/libavcodec/libpostproc/postprocess_template.c.orig	Tue Oct  5 14:36:15 2004
+++ ffmpeg/libavcodec/libpostproc/postprocess_template.c	Tue Oct  5 14:34:29 2004
@@ -49,6 +49,8 @@
 	"paddb " #a ", " #b " \n\t"
 #endif
 
+int xxx;
+
 //FIXME? |255-0| = 1 (shouldnt be a problem ...)
 #ifdef HAVE_MMX
 /**
@@ -2870,7 +2872,7 @@
 		);
 
 		src+= step; // src points to begin of the 8x8 Block
-                int xxx = dc_mask & eq_mask;
+                xxx = dc_mask & eq_mask;
 		asm volatile(
 		"movq %4, %%mm6					\n\t"
 		"pcmpeqb %%mm5, %%mm5				\n\t"
