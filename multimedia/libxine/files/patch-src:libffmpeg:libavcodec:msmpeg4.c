--- src/libffmpeg/libavcodec/msmpeg4.c.orig	Wed Aug  4 17:27:04 2004
+++ src/libffmpeg/libavcodec/msmpeg4.c	Wed Aug  4 17:27:37 2004
@@ -60,8 +60,8 @@
 static uint32_t v2_dc_chroma_table[512][2];
 
 static inline void msmpeg4_encode_block(MpegEncContext * s, DCTELEM * block, int n);
-static inline int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
-                                       int n, int coded, const uint8_t *scantable);
+static int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+				int n, int coded, const uint8_t *scantable);
 static int msmpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr);
 static int msmpeg4_decode_motion(MpegEncContext * s, 
                                  int *mx_ptr, int *my_ptr);
@@ -1656,8 +1656,8 @@
     return 0;
 }
 //#define ERROR_DETAILS
-static inline int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
-                              int n, int coded, const uint8_t *scan_table)
+static int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+				int n, int coded, const uint8_t *scan_table)
 {
     int level, i, last, run, run_diff;
     int dc_pred_dir;
