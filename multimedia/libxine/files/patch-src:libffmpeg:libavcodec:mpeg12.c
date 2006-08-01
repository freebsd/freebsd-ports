--- src/libffmpeg/libavcodec/mpeg12.c.orig	Sun Jul  9 23:38:32 2006
+++ src/libffmpeg/libavcodec/mpeg12.c	Wed Aug  2 01:25:48 2006
@@ -65,21 +65,21 @@
                          int component);
 static void mpeg1_encode_motion(MpegEncContext *s, int val, int f_or_b_code);    // RAL: f_code parameter added
 #endif //CONFIG_ENCODERS
-static inline int mpeg1_decode_block_inter(MpegEncContext *s,
+static __inline int mpeg1_decode_block_inter(MpegEncContext *s,
                               DCTELEM *block,
                               int n);
-static inline int mpeg1_decode_block_intra(MpegEncContext *s,
+static __inline int mpeg1_decode_block_intra(MpegEncContext *s,
                               DCTELEM *block,
                               int n);
-static inline int mpeg1_fast_decode_block_inter(MpegEncContext *s, DCTELEM *block, int n);
-static inline int mpeg2_decode_block_non_intra(MpegEncContext *s,
+static __inline int mpeg1_fast_decode_block_inter(MpegEncContext *s, DCTELEM *block, int n);
+static __inline int mpeg2_decode_block_non_intra(MpegEncContext *s,
                                         DCTELEM *block,
                                         int n);
-static inline int mpeg2_decode_block_intra(MpegEncContext *s,
+static __inline int mpeg2_decode_block_intra(MpegEncContext *s,
                                     DCTELEM *block,
                                     int n);
-static inline int mpeg2_fast_decode_block_non_intra(MpegEncContext *s, DCTELEM *block, int n);
-static inline int mpeg2_fast_decode_block_intra(MpegEncContext *s, DCTELEM *block, int n);
+static __inline int mpeg2_fast_decode_block_non_intra(MpegEncContext *s, DCTELEM *block, int n);
+static __inline int mpeg2_fast_decode_block_intra(MpegEncContext *s, DCTELEM *block, int n);
 static int mpeg_decode_motion(MpegEncContext *s, int fcode, int pred);
 static void exchange_uv(MpegEncContext *s);
 
@@ -1505,7 +1505,7 @@
     return diff;
 }
 
-static inline int mpeg1_decode_block_intra(MpegEncContext *s,
+static __inline int mpeg1_decode_block_intra(MpegEncContext *s,
                                DCTELEM *block,
                                int n)
 {
@@ -1578,7 +1578,7 @@
    return 0;
 }
 
-static inline int mpeg1_decode_block_inter(MpegEncContext *s,
+static __inline int mpeg1_decode_block_inter(MpegEncContext *s,
                                DCTELEM *block,
                                int n)
 {
@@ -1656,7 +1656,7 @@
     return 0;
 }
 
-static inline int mpeg1_fast_decode_block_inter(MpegEncContext *s, DCTELEM *block, int n)
+static __inline int mpeg1_fast_decode_block_inter(MpegEncContext *s, DCTELEM *block, int n)
 {
     int level, i, j, run;
     RLTable *rl = &rl_mpeg1;
@@ -1728,7 +1728,7 @@
 }
 
 
-static inline int mpeg2_decode_block_non_intra(MpegEncContext *s,
+static __inline int mpeg2_decode_block_non_intra(MpegEncContext *s,
                                DCTELEM *block,
                                int n)
 {
@@ -1809,7 +1809,7 @@
     return 0;
 }
 
-static inline int mpeg2_fast_decode_block_non_intra(MpegEncContext *s,
+static __inline int mpeg2_fast_decode_block_non_intra(MpegEncContext *s,
                                DCTELEM *block,
                                int n)
 {
@@ -1872,7 +1872,7 @@
 }
 
 
-static inline int mpeg2_decode_block_intra(MpegEncContext *s,
+static __inline int mpeg2_decode_block_intra(MpegEncContext *s,
                                DCTELEM *block,
                                int n)
 {
@@ -1952,7 +1952,7 @@
     return 0;
 }
 
-static inline int mpeg2_fast_decode_block_intra(MpegEncContext *s,
+static __inline int mpeg2_fast_decode_block_intra(MpegEncContext *s,
                                DCTELEM *block,
                                int n)
 {
