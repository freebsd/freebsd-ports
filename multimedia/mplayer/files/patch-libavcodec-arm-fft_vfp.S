--- ffmpeg/libavcodec/arm/fft_vfp.S.orig	2014-12-09 19:20:07.000000000 +0100
+++ ffmpeg/libavcodec/arm/fft_vfp.S	2014-12-24 15:48:09.494735677 +0100
@@ -33,7 +33,7 @@
         movrel  a2, (fft_tab_vfp - 8)
         ldr     pc, [a2, ip, lsl #2]
 endfunc
-const   fft_tab_vfp, relocate=1
+const   fft_tab_vfp
         .word   fft4_vfp
         .word   fft8_vfp
         .word   X(ff_fft16_vfp)     @ this one alone is exported
