--- ffmpeg/libavcodec/i386/dsputil_mmx.c.orig	Wed Nov 17 17:30:15 2004
+++ ffmpeg/libavcodec/i386/dsputil_mmx.c	Wed Nov 17 17:30:33 2004
@@ -31,8 +31,8 @@
 static const uint64_t mm_wone __attribute__ ((aligned(8))) = 0x0001000100010001ULL;
 static const uint64_t mm_wtwo __attribute__ ((aligned(8))) = 0x0002000200020002ULL;
 
-static const uint64_t ff_pw_20 __attribute__ ((aligned(8))) = 0x0014001400140014ULL;
-static const uint64_t ff_pw_3  __attribute__ ((aligned(8))) = 0x0003000300030003ULL;
+static const uint64_t ff_pw_20 __attribute__ ((aligned(8), used)) = 0x0014001400140014ULL;
+static const uint64_t ff_pw_3  __attribute__ ((aligned(8), used)) = 0x0003000300030003ULL;
 static const uint64_t ff_pw_16 __attribute__ ((aligned(8))) = 0x0010001000100010ULL;
 static const uint64_t ff_pw_15 __attribute__ ((aligned(8))) = 0x000F000F000F000FULL;

