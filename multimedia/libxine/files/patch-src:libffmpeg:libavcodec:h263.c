--- src/libffmpeg/libavcodec/h263.c.orig	Sun Sep 12 21:17:13 2004
+++ src/libffmpeg/libavcodec/h263.c	Mon Nov 15 01:05:07 2004
@@ -63,7 +63,7 @@
 static int h263p_decode_umotion(MpegEncContext * s, int pred);
 static int h263_decode_block(MpegEncContext * s, DCTELEM * block,
                              int n, int coded);
-static inline int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, int intra, int rvlc);
 static int h263_pred_dc(MpegEncContext * s, int n, uint16_t **dc_val_ptr);
 #ifdef CONFIG_ENCODERS
@@ -3279,7 +3279,7 @@
  * @param dir_ptr the prediction direction will be stored here
  * @return the quantized dc
  */
-static inline int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr)
+static int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr)
 {
     int level, code;
 
@@ -3629,7 +3629,7 @@
  * decodes a block.
  * @return <0 if an error occured
  */
-static inline int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, int intra, int rvlc)
 {
     int level, i, last, run;
