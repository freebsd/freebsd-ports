--- src/libffmpeg/libavcodec/mpeg12.c.orig	Wed Aug  4 17:16:09 2004
+++ src/libffmpeg/libavcodec/mpeg12.c	Wed Aug  4 17:19:51 2004
@@ -65,16 +65,16 @@
                          int component);
 static void mpeg1_encode_motion(MpegEncContext *s, int val, int f_or_b_code);    // RAL: f_code parameter added
 #endif //CONFIG_ENCODERS
-static inline int mpeg1_decode_block_inter(MpegEncContext *s, 
-                              DCTELEM *block, 
-                              int n);
-static inline int mpeg1_decode_block_intra(MpegEncContext *s, 
-                              DCTELEM *block, 
-                              int n);
-static inline int mpeg2_decode_block_non_intra(MpegEncContext *s, 
+static int mpeg1_decode_block_inter(MpegEncContext *s, 
+				    DCTELEM *block, 
+				    int n);
+static int mpeg1_decode_block_intra(MpegEncContext *s, 
+				    DCTELEM *block, 
+				    int n);
+static int mpeg2_decode_block_non_intra(MpegEncContext *s, 
                                         DCTELEM *block, 
                                         int n);
-static inline int mpeg2_decode_block_intra(MpegEncContext *s, 
+static int mpeg2_decode_block_intra(MpegEncContext *s, 
                                     DCTELEM *block, 
                                     int n);
 static int mpeg_decode_motion(MpegEncContext *s, int fcode, int pred);
@@ -1463,9 +1463,9 @@
     return diff;
 }
 
-static inline int mpeg1_decode_block_intra(MpegEncContext *s, 
-                               DCTELEM *block, 
-                               int n)
+static int mpeg1_decode_block_intra(MpegEncContext *s, 
+				    DCTELEM *block, 
+				    int n)
 {
     int level, dc, diff, i, j, run;
     int component;
@@ -1536,9 +1536,9 @@
    return 0;
 }
 
-static inline int mpeg1_decode_block_inter(MpegEncContext *s, 
-                               DCTELEM *block, 
-                               int n)
+static int mpeg1_decode_block_inter(MpegEncContext *s, 
+				    DCTELEM *block, 
+				    int n)
 {
     int level, i, j, run;
     RLTable *rl = &rl_mpeg1;
@@ -1614,9 +1614,9 @@
 
 /* Also does unquantization here, since I will never support mpeg2
    encoding */
-static inline int mpeg2_decode_block_non_intra(MpegEncContext *s, 
-                               DCTELEM *block, 
-                               int n)
+static int mpeg2_decode_block_non_intra(MpegEncContext *s, 
+					DCTELEM *block, 
+					int n)
 {
     int level, i, j, run;
     RLTable *rl = &rl_mpeg1;
@@ -1693,9 +1693,9 @@
     return 0;
 }
 
-static inline int mpeg2_decode_block_intra(MpegEncContext *s, 
-                               DCTELEM *block, 
-                               int n)
+static int mpeg2_decode_block_intra(MpegEncContext *s, 
+				    DCTELEM *block, 
+				    int n)
 {
     int level, dc, diff, i, j, run;
     int component;
