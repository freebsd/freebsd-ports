--- src/libffmpeg/libavcodec/msmpeg4.c.orig	Sun Sep 12 21:17:14 2004
+++ src/libffmpeg/libavcodec/msmpeg4.c	Mon Nov 15 01:10:50 2004
@@ -64,7 +64,7 @@
                                  int *mx_ptr, int *my_ptr);
 static void msmpeg4v2_encode_motion(MpegEncContext * s, int val);
 static void init_h263_dc_for_msmpeg4(void);
-static inline void msmpeg4_memsetw(short *tab, int val, int n);
+static void msmpeg4_memsetw(short *tab, int val, int n);
 #ifdef CONFIG_ENCODERS
 static int get_size_of_code(MpegEncContext * s, RLTable *rl, int last, int run, int level, int intra);
 static void msmpeg4_encode_dc(MpegEncContext * s, int level, int n, int *dir_ptr);
@@ -1478,8 +1478,8 @@
 }
 
 //#define ERROR_DETAILS
-static inline int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
-                              int n, int coded, const uint8_t *scan_table)
+static int msmpeg4_decode_block(MpegEncContext * s, DCTELEM * block,
+				int n, int coded, const uint8_t *scan_table)
 {
     int level, i, last, run, run_diff;
     int dc_pred_dir;
