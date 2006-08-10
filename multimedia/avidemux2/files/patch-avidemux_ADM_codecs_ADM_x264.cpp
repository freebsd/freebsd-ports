--- avidemux/ADM_codecs/ADM_x264.cpp.orig	Thu Aug 10 07:44:45 2006
+++ avidemux/ADM_codecs/ADM_x264.cpp	Thu Aug 10 07:45:53 2006
@@ -200,7 +200,7 @@
 {
   memset(&param,0,sizeof(param));
   x264_param_default( &param );
-  param.rc.b_cbr=1;
+  param.rc.i_rc_method = X264_RC_CQP;
   param.rc.i_bitrate=val/1000;  
 //  param.rc.i_rc_buffer_size=val/1000;
 //  param.rc.i_rc_init_buffer=(val/1000)>>1;
@@ -234,7 +234,7 @@
   memset(&param,0,sizeof(param));
   x264_param_default( &param );
   
-  param.rc.b_cbr=1;
+  param.rc.i_rc_method = X264_RC_CQP;
   param.rc.i_bitrate=val;  
   //param.rc.i_rc_buffer_size=val;
   //param.rc.i_rc_init_buffer=val>>1;
