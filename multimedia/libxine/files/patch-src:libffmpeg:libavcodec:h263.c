--- src/libffmpeg/libavcodec/h263.c.orig	Fri Dec 16 00:57:15 2005
+++ src/libffmpeg/libavcodec/h263.c	Fri Dec 16 01:00:23 2005
@@ -66,8 +66,8 @@
 static int h263p_decode_umotion(MpegEncContext * s, int pred);
 static int h263_decode_block(MpegEncContext * s, DCTELEM * block,
                              int n, int coded);
-static inline int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr);
-static inline int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr);
+static int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, int intra, int rvlc);
 static int mpeg4_get_block_length(MpegEncContext * s, DCTELEM * block, int n, int intra_dc, 
                                uint8_t *scan_table);
@@ -4682,7 +4682,7 @@
  * @param dir_ptr the prediction direction will be stored here
  * @return the quantized dc
  */
-static inline int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr)
+static int mpeg4_decode_dc(MpegEncContext * s, int n, int *dir_ptr)
 {
     int level, code;
 
@@ -4727,7 +4727,7 @@
  * decodes a block.
  * @return <0 if an error occured
  */
-static inline int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+static int mpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
                               int n, int coded, int intra, int rvlc)
 {
     int level, i, last, run;
