--- ffmpeg/libavcodec/i386/motion_est_mmx.c.orig	Wed Nov 17 17:31:38 2004
+++ ffmpeg/libavcodec/i386/motion_est_mmx.c	Wed Nov 17 17:31:47 2004
@@ -26,7 +26,7 @@
 0x0002000200020002ULL,
 };
 
-static __attribute__ ((aligned(8), unused)) uint64_t bone= 0x0101010101010101LL;
+static __attribute__ ((aligned(8), used)) uint64_t bone= 0x0101010101010101LL;
 
 static inline void sad8_mmx(uint8_t *blk1, uint8_t *blk2, int stride, int h)
 {

