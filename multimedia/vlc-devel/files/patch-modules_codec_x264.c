--- modules/codec/x264.c.orig	Wed Aug  9 21:24:08 2006
+++ modules/codec/x264.c	Wed Aug  9 21:24:27 2006
@@ -588,7 +588,7 @@
 
     /* cbr = 1 overrides qp or crf and sets an average bitrate
        but maxrate = average bitrate is needed for "real" CBR */
-    if( p_sys->param.rc.i_bitrate > 0 ) p_sys->param.rc.b_cbr = 1;
+    if( p_sys->param.rc.i_bitrate > 0 ) p_sys->param.rc.i_rc_method = 1;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "qpstep", &val );
     if( val.i_int >= 0 && val.i_int <= 51 ) p_sys->param.rc.i_qp_step = val.i_int;
