--- ffmpeg/libavcodec/i386/simple_idct_mmx.c.orig	Wed Nov 17 17:32:21 2004
+++ ffmpeg/libavcodec/i386/simple_idct_mmx.c	Wed Nov 17 17:32:37 2004
@@ -45,8 +45,8 @@
 #define ROW_SHIFT 11
 #define COL_SHIFT 20 // 6
 
-static const uint64_t __attribute__((aligned(8))) wm1010= 0xFFFF0000FFFF0000ULL;
-static const uint64_t __attribute__((aligned(8))) d40000= 0x0000000000040000ULL;
+static const uint64_t __attribute__((aligned(8), used)) wm1010= 0xFFFF0000FFFF0000ULL;
+static const uint64_t __attribute__((aligned(8), used)) d40000= 0x0000000000040000ULL;
 
 static const int16_t __attribute__((aligned(8))) coeffs[]= {
 	1<<(ROW_SHIFT-1), 0, 1<<(ROW_SHIFT-1), 0,


