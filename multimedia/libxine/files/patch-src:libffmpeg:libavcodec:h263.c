--- src/libffmpeg/libavcodec/h263.c.orig	Sun May 30 19:24:19 2004
+++ src/libffmpeg/libavcodec/h263.c	Sun Aug  1 12:52:11 2004
@@ -66,8 +66,8 @@
 static int h263p_decode_umotion(MpegEncContext * s, int pred);
 static int h263_decode_block(MpegEncContext * s, DCTELEM * block,
                              int n, int coded);
-static inline int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr);
-static inline int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr);
+static int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, int intra, int rvlc);
 static int h263_pred_dc(MpegEncContext * s, int n, uint16_t **dc_val_ptr);
 #ifdef CONFIG_ENCODERS
@@ -4548,7 +4548,7 @@
  * @param dir_ptr the prediction direction will be stored here
  * @return the quantized dc
  */
-static inline int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr)
+static int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr)
 {
     int level, code;
 
@@ -4593,7 +4593,7 @@
  * decodes a block.
  * @return <0 if an error occured
  */
-static inline int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, int intra, int rvlc)
 {
     int level, i, last, run;
