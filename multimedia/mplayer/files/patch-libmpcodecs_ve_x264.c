--- libmpcodecs/ve_x264.c.orig	Wed Aug  9 21:05:29 2006
+++ libmpcodecs/ve_x264.c	Wed Aug  9 21:06:26 2006
@@ -275,7 +275,7 @@
                    "VBV requires both vbv_maxrate and vbv_bufsize.\n");
             return 0;
         }
-        mod->param.rc.b_cbr = 1;
+        mod->param.rc.i_rc_method = 1;
         mod->param.rc.i_bitrate = bitrate;
         mod->param.rc.f_rate_tolerance = ratetol;
         mod->param.rc.i_vbv_max_bitrate = vbv_maxrate;
