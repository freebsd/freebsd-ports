--- encoder/encoder.c.orig	Tue Jan 25 21:28:32 2005
+++ encoder/encoder.c	Tue Jan 25 21:30:21 2005
@@ -1113,12 +1113,14 @@
     if( i_slice_type == SLICE_TYPE_P && !h->param.rc.b_stat_read 
         && h->param.i_scenecut_threshold >= 0 )
     {
+        int i_gop_size;
         int i_mb_i = h->stat.frame.i_mb_count[I_4x4] + h->stat.frame.i_mb_count[I_16x16];
         int i_mb_p = h->stat.frame.i_mb_count[P_L0] + h->stat.frame.i_mb_count[P_8x8];
         int i_mb_s = h->stat.frame.i_mb_count[P_SKIP];
         int i_mb   = h->sps->i_mb_width * h->sps->i_mb_height;
         int64_t i_inter_cost = h->stat.frame.i_inter_cost;
         int64_t i_intra_cost = h->stat.frame.i_intra_cost;
+        float f_bias;
 
         float f_thresh_max = h->param.i_scenecut_threshold / 100.0;
         /* ratio of 10 pulled out of thin air */
@@ -1126,8 +1128,7 @@
                              / ( h->param.i_keyint_max * 4 );
         if( h->param.i_keyint_min == h->param.i_keyint_max )
              f_thresh_min= f_thresh_max;
-        float f_bias;
-        int i_gop_size = h->fenc->i_frame - h->frames.i_last_idr;
+	i_gop_size = h->fenc->i_frame - h->frames.i_last_idr;
 
         /* macroblock_analyse() doesn't further analyse skipped mbs,
          * so we have to guess their cost */
