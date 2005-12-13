--- src/libffmpeg/libavcodec/h263.c.orig	Tue Dec 13 22:39:59 2005
+++ src/libffmpeg/libavcodec/h263.c	Tue Dec 13 22:41:08 2005
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
