--- libmpcodecs/ve_x264.c.orig	Sun Jun 11 18:35:41 2006
+++ libmpcodecs/ve_x264.c	Fri Nov  3 17:05:22 2006
@@ -208,7 +208,7 @@
 };
 
 static int parse_cqm(const char *str, uint8_t *cqm, int length,
-                     h264_module_t *mod, char *matrix_name) {
+                     h264_module_t *mod, const char *matrix_name) {
     int i;
     if (!str) return 0;
     for (i = 0; i < length; i++) {
@@ -247,8 +247,11 @@
     mod->param.i_deblocking_filter_beta = deblockbeta;
     mod->param.b_cabac = cabac;
 
+    mod->param.rc.i_rc_method = X264_RC_CQP;
     mod->param.rc.i_qp_constant = qp_constant;
-    mod->param.rc.i_rf_constant = rf_constant;
+    if(rf_constant > 0)
+        mod->param.rc.i_rc_method = X264_RC_CRF;
+    mod->param.rc.f_rf_constant = rf_constant;
     if(qp_min > qp_constant)
         qp_min = qp_constant;
     if(qp_max < qp_constant)
@@ -275,7 +278,7 @@
                    "VBV requires both vbv_maxrate and vbv_bufsize.\n");
             return 0;
         }
-        mod->param.rc.b_cbr = 1;
+        mod->param.rc.i_rc_method = X264_RC_ABR;
         mod->param.rc.i_bitrate = bitrate;
         mod->param.rc.f_rate_tolerance = ratetol;
         mod->param.rc.i_vbv_max_bitrate = vbv_maxrate;
