--- modules/codec/x264.c.orig	Thu Nov 11 13:50:16 2004
+++ modules/codec/x264.c	Wed Jan 26 05:03:04 2005
@@ -236,10 +236,11 @@
     p_sys->param.b_deblocking_filter = val.b_bool;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "keyint", &val );
-    if( val.i_int > 0 ) p_sys->param.i_iframe = val.i_int;
+	if( val.i_int > 0 ) p_sys->param.i_keyint_max = val.i_int;
+	if( val.i_int > 0 ) p_sys->param.i_keyint_min = val.i_int * 0.4;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "idrint", &val );
-    if( val.i_int > 0 ) p_sys->param.i_idrframe = val.i_int;
+	if( val.i_int > 0 ) p_sys->param.i_keyint_min = val.i_int;
 
     var_Get( p_enc, SOUT_CFG_PREFIX "bframes", &val );
     if( val.i_int >= 0 && val.i_int <= 16 ) p_sys->param.i_bframe = val.i_int;
