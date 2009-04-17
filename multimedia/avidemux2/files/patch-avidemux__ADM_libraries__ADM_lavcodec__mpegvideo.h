--- avidemux/ADM_libraries/ADM_lavcodec/mpegvideo.h.orig	2007-07-16 21:46:57.000000000 +0400
+++ avidemux/ADM_libraries/ADM_lavcodec/mpegvideo.h	2009-04-16 20:54:12.000000000 +0400
@@ -781,10 +781,10 @@
                      int16_t (*mv_table)[2], int f_code, int type, int truncate);
 void ff_init_me(MpegEncContext *s);
 int ff_pre_estimate_p_frame_motion(MpegEncContext * s, int mb_x, int mb_y);
-inline int ff_epzs_motion_search(MpegEncContext * s, int *mx_ptr, int *my_ptr,
+int ff_epzs_motion_search(MpegEncContext * s, int *mx_ptr, int *my_ptr,
                              int P[10][2], int src_index, int ref_index, int16_t (*last_mv)[2],
                              int ref_mv_scale, int size, int h);
-inline int ff_get_mb_score(MpegEncContext * s, int mx, int my, int src_index,
+int ff_get_mb_score(MpegEncContext * s, int mx, int my, int src_index,
                                int ref_index, int size, int h, int add_rate);
 
 /* mpeg12.c */
