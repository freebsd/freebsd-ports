--- ffmpeg/libavcodec/liba52/resample_mmx.c.orig	Fri Aug  6 13:59:15 2004
+++ ffmpeg/libavcodec/liba52/resample_mmx.c	Fri Aug  6 14:09:51 2004
@@ -7,10 +7,10 @@
 	and it would mean (C / MMX2 / MMX / 3DNOW) versions 
 */
 
-static uint64_t __attribute__((aligned(8))) magicF2W= 0x43c0000043c00000LL;
-static uint64_t __attribute__((aligned(8))) wm1010= 0xFFFF0000FFFF0000LL;
-static uint64_t __attribute__((aligned(8))) wm0101= 0x0000FFFF0000FFFFLL;
-static uint64_t __attribute__((aligned(8))) wm1100= 0xFFFFFFFF00000000LL;
+static uint64_t __attribute__((aligned(8))) __attribute__((used)) magicF2W= 0x43c0000043c00000LL;
+static uint64_t __attribute__((aligned(8))) __attribute__((used)) wm1010= 0xFFFF0000FFFF0000LL;
+static uint64_t __attribute__((aligned(8))) __attribute__((used)) wm0101= 0x0000FFFF0000FFFFLL;
+static uint64_t __attribute__((aligned(8))) __attribute__((used)) wm1100= 0xFFFFFFFF00000000LL;
 
 static int a52_resample_MONO_to_5_MMX(float * _f, int16_t * s16){
     int32_t * f = (int32_t *) _f;
