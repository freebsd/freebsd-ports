--- src/libffmpeg/libavcodec/msmpeg4.c.orig	Fri Dec 16 01:17:22 2005
+++ src/libffmpeg/libavcodec/msmpeg4.c	Fri Dec 16 01:18:00 2005
@@ -60,7 +60,7 @@
 static uint32_t v2_dc_chroma_table[512][2];
 
 static inline void msmpeg4_encode_block(MpegEncContext * s, DCTELEM * block, int n);
-static inline int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                                        int n, int coded, const uint8_t *scantable);
 static int msmpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr);
 static int msmpeg4_decode_motion(MpegEncContext * s, 
@@ -1659,7 +1659,7 @@
     return 0;
 }
 //#define ERROR_DETAILS
-static inline int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, const uint8_t *scan_table)
 {
     int level, i, last, run, run_diff;
