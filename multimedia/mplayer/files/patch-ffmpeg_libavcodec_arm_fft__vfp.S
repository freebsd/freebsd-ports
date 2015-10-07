--- ffmpeg/libavcodec/arm/fft_vfp.S.orig	2015-06-19 20:44:37 UTC
+++ ffmpeg/libavcodec/arm/fft_vfp.S
@@ -33,7 +33,7 @@ function ff_fft_calc_vfp, export=1
         movrel  a2, (fft_tab_vfp - 8)
         ldr     pc, [a2, ip, lsl #2]
 endfunc
-const   fft_tab_vfp, relocate=1
+const   fft_tab_vfp
         .word   fft4_vfp
         .word   fft8_vfp
         .word   X(ff_fft16_vfp)     @ this one alone is exported
