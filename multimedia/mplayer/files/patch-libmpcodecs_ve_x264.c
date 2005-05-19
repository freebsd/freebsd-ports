--- libmpcodecs/ve_x264.c.orig	Wed Apr 13 15:10:29 2005
+++ libmpcodecs/ve_x264.c	Wed May 11 12:00:12 2005
@@ -62,7 +62,7 @@
 static int qp_constant = 26;
 static int frame_ref = 1;
 static int keyint_max = 250;
-static int keyint_min = -1;
+static int keyint_min = 25;
 static int scenecut_threshold = 40;
 static int bframe = 0;
 static int bframe_adaptive = 1;
@@ -81,18 +81,21 @@
 static int chroma_qp_offset = 0;
 static float ip_factor = 1.4;
 static float pb_factor = 1.3;
-static int rc_buffer_size = -1;
-static float rc_init_buffer = 0.25;
-static int rc_sens = 4;
+static float ratetol = 1.0;
+static int vbv_maxrate = 0;
+static int vbv_bufsize = 0;
+static float vbv_init = 0.9;
 static int qp_min = 10;
 static int qp_max = 51;
-static int qp_step = 1;
+static int qp_step = 2;
 static int pass = 0;
 static float qcomp = 0.6;
 static float qblur = 0.5;
 static float complexity_blur = 20;
 static char *rc_eq = "blurCplx^(1-qComp)";
 static int subq = 5;
+static int me_method = 2;
+static int me_range = 16;
 static int level_idc = 40;
 static int psnr = 0;
 static int log_level = 2;
@@ -130,9 +133,10 @@
     {"chroma_qp_offset", &chroma_qp_offset, CONF_TYPE_INT, CONF_RANGE, -12, 12, NULL},
     {"ip_factor", &ip_factor, CONF_TYPE_FLOAT, CONF_RANGE, -10.0, 10.0, NULL},
     {"pb_factor", &pb_factor, CONF_TYPE_FLOAT, CONF_RANGE, -10.0, 10.0, NULL},
-    {"rc_buffer_size", &rc_buffer_size, CONF_TYPE_INT, CONF_RANGE, 0, 24000000, NULL},
-    {"rc_init_buffer", &rc_init_buffer, CONF_TYPE_FLOAT, CONF_RANGE, 0, 24000000, NULL},
-    {"rc_sens", &rc_sens, CONF_TYPE_INT, CONF_RANGE, 0, 100, NULL},
+    {"ratetol", &ratetol, CONF_TYPE_FLOAT, CONF_RANGE, 0.1, 100.0, NULL},
+    {"vbv_maxrate", &vbv_maxrate, CONF_TYPE_INT, CONF_RANGE, 0, 24000000, NULL},
+    {"vbv_bufsize", &vbv_bufsize, CONF_TYPE_INT, CONF_RANGE, 0, 24000000, NULL},
+    {"vbv_init", &vbv_init, CONF_TYPE_FLOAT, CONF_RANGE, 0.0, 1.0, NULL},
     {"qp_min", &qp_min, CONF_TYPE_INT, CONF_RANGE, 1, 51, NULL},
     {"qp_max", &qp_max, CONF_TYPE_INT, CONF_RANGE, 1, 51, NULL},
     {"qp_step", &qp_step, CONF_TYPE_INT, CONF_RANGE, 1, 50, NULL},
@@ -142,6 +146,8 @@
     {"qblur", &qblur, CONF_TYPE_FLOAT, CONF_RANGE, 0, 99, NULL},
     {"cplx_blur", &complexity_blur, CONF_TYPE_FLOAT, CONF_RANGE, 0, 999, NULL},
     {"subq", &subq, CONF_TYPE_INT, CONF_RANGE, 1, 5, NULL},
+    {"me", &me_method, CONF_TYPE_INT, CONF_RANGE, 1, 3, NULL},
+    {"me_range", &me_range, CONF_TYPE_INT, CONF_RANGE, 4, 64, NULL},
     {"level_idc", &level_idc, CONF_TYPE_INT, CONF_RANGE, 10, 51, NULL},
     {"psnr", &psnr, CONF_TYPE_FLAG, 0, 0, 1, NULL},
     {"nopsnr", &psnr, CONF_TYPE_FLAG, 0, 1, 0, NULL},
@@ -161,7 +167,7 @@
     x264_param_default(&mod->param);
     mod->param.i_frame_reference = frame_ref;
     mod->param.i_keyint_max = keyint_max;
-    mod->param.i_keyint_min = keyint_min > 0 ? keyint_min : keyint_max * 2 / 5;
+    mod->param.i_keyint_min = keyint_min;
     mod->param.i_scenecut_threshold = scenecut_threshold;
     mod->param.i_bframe = bframe;
     mod->param.b_bframe_adaptive = bframe_adaptive;
@@ -185,6 +191,7 @@
     mod->param.rc.f_qblur = qblur;
     mod->param.rc.f_complexity_blur = complexity_blur;
     mod->param.analyse.i_subpel_refine = subq;
+    mod->param.analyse.i_me_method = subq==1 ? X264_ME_DIA : X264_ME_HEX;
     mod->param.rc.psz_stat_out = passtmpfile;
     mod->param.rc.psz_stat_in = passtmpfile;
     if((pass & 2) && bitrate <= 0)
@@ -212,19 +219,26 @@
         break;
     }
     if(bitrate > 0) {
-        if(rc_buffer_size <= 0)
-            rc_buffer_size = bitrate;
+        if((vbv_maxrate > 0) != (vbv_bufsize > 0)) {
+            mp_msg(MSGT_MENCODER, MSGL_ERR,
+                   "VBV requires both vbv_maxrate and vbv_bufsize.\n");
+            return 0;
+        }
         mod->param.rc.b_cbr = 1;
         mod->param.rc.i_bitrate = bitrate;
-        mod->param.rc.i_rc_buffer_size = rc_buffer_size;
-        if(rc_init_buffer > 1)
-            mod->param.rc.i_rc_init_buffer = rc_init_buffer;
-        else
-            mod->param.rc.i_rc_init_buffer = rc_buffer_size * rc_init_buffer;
-        mod->param.rc.i_rc_sens = rc_sens;
+        mod->param.rc.f_rate_tolerance = ratetol;
+        mod->param.rc.i_vbv_max_bitrate = vbv_maxrate;
+        mod->param.rc.i_vbv_buffer_size = vbv_bufsize;
+        mod->param.rc.f_vbv_buffer_init = vbv_init;
     }
     mod->param.rc.f_ip_factor = ip_factor;
     mod->param.rc.f_pb_factor = pb_factor;
+    switch(me_method) {
+        case 1: mod->param.analyse.i_me_method = X264_ME_DIA; break;
+        case 2: mod->param.analyse.i_me_method = X264_ME_HEX; break;
+        case 3: mod->param.analyse.i_me_method = X264_ME_ESA;
+                mod->param.analyse.i_me_range = me_range; break;
+    }
     mod->param.analyse.inter = X264_ANALYSE_I4x4;
     if(p4x4mv)
         mod->param.analyse.inter |= X264_ANALYSE_PSUB8x8;
