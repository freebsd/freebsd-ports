--- output/mp4.c.orig	2020-07-02 16:50:47 UTC
+++ output/mp4.c
@@ -147,7 +147,7 @@ static int close_file( hnd_t handle, int64_t largest_p
             {
                 uint32_t mvhd_timescale = gf_isom_get_timescale( p_mp4->p_file );
                 uint64_t tkhd_duration = (uint64_t)( mdhd_duration * ( (double)mvhd_timescale / p_mp4->i_time_res ) );
-                gf_isom_append_edit_segment( p_mp4->p_file, p_mp4->i_track, tkhd_duration, sample->CTS_Offset, GF_ISOM_EDIT_NORMAL );
+                gf_isom_append_edit( p_mp4->p_file, p_mp4->i_track, tkhd_duration, sample->CTS_Offset, GF_ISOM_EDIT_NORMAL );
             }
             gf_isom_sample_del( &sample );
 
@@ -233,7 +233,7 @@ static int set_param( hnd_t handle, x264_param_t *p_pa
             dw *= sar;
         else
             dh /= sar;
-        gf_isom_set_pixel_aspect_ratio( p_mp4->p_file, p_mp4->i_track, p_mp4->i_descidx, p_param->vui.i_sar_width, p_param->vui.i_sar_height );
+        gf_isom_set_pixel_aspect_ratio( p_mp4->p_file, p_mp4->i_track, p_mp4->i_descidx, p_param->vui.i_sar_width, p_param->vui.i_sar_height, 0 );
         gf_isom_set_track_layout_info( p_mp4->p_file, p_mp4->i_track, dw, dh, 0, 0, 0 );
     }
 
