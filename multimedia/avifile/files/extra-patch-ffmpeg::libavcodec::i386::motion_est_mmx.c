--- ffmpeg/libavcodec/i386/motion_est_mmx.c.orig	Fri Aug  6 13:59:15 2004
+++ ffmpeg/libavcodec/i386/motion_est_mmx.c	Fri Aug  6 14:08:21 2004
@@ -26,7 +26,7 @@
 0x0002000200020002,
 };
 
-static __attribute__ ((aligned(8))) uint64_t bone= 0x0101010101010101LL;
+static __attribute__((aligned(8))) __attribute__((used)) uint64_t bone= 0x0101010101010101LL;
 
 static inline void sad8_mmx(uint8_t *blk1, uint8_t *blk2, int stride, int h)
 {
