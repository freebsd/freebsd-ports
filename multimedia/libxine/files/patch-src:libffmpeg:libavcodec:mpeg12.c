--- src/libffmpeg/libavcodec/mpeg12.c.orig	Sun Sep 12 21:17:14 2004
+++ src/libffmpeg/libavcodec/mpeg12.c	Mon Nov 15 01:06:46 2004
@@ -1044,9 +1044,9 @@
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
@@ -1117,9 +1117,9 @@
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
@@ -1195,9 +1195,9 @@
 
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
@@ -1274,9 +1274,9 @@
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
