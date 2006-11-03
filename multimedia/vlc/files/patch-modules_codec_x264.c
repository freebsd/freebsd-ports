--- modules/codec/x264.c.orig	Sat May  6 15:52:19 2006
+++ modules/codec/x264.c	Fri Nov  3 16:47:49 2006
@@ -547,7 +547,7 @@
 
     /* cbr = 1 overrides qp or crf and sets an average bitrate
        but maxrate = average bitrate is needed for "real" CBR */
-    if( p_sys->param.rc.i_bitrate > 0 ) p_sys->param.rc.b_cbr = 1;
+    if( p_sys->param.rc.i_bitrate > 0 ) p_sys->param.rc.i_rc_method = 1;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "qpstep", &val );
     if( val.i_int >= 0 && val.i_int <= 51 ) p_sys->param.rc.i_qp_step = val.i_int;
@@ -737,7 +737,11 @@
 #if X264_BUILD >= 37
     var_Get( p_enc, SOUT_CFG_PREFIX "crf", &val ); 
     if( val.i_int >= 0 && val.i_int <= 51 ) /* crf != 0 overrides qp */
+#if X264_BUILD >= 54
+        p_sys->param.rc.f_rf_constant = val.i_int;
+#else
         p_sys->param.rc.i_rf_constant = val.i_int;
+#endif
 #endif
 
 #if X264_BUILD >= 39
