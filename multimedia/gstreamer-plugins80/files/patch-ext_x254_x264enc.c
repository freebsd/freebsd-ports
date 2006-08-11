--- ext/x264/x264enc.c.orig	Fri Aug 11 07:34:14 2006
+++ ext/x264/x264enc.c	Fri Aug 11 07:35:44 2006
@@ -460,7 +460,7 @@
       g_value_set_enum (val, x264->params.b_cabac);
       break;
     case ARG_CBR:
-      g_value_set_boolean (val, x264->params.rc.b_cbr);
+      g_value_set_boolean (val, x264->params.rc.i_rc_method);
       break;
     case ARG_BITRATE:
       g_value_set_int (val, x264->params.rc.i_bitrate);
@@ -503,7 +503,7 @@
       x264->params.b_cabac = g_value_get_enum (val);
       break;
     case ARG_CBR:
-      x264->params.rc.b_cbr = g_value_get_boolean (val);
+      x264->params.rc.i_rc_method = g_value_get_boolean (val);
       break;
     case ARG_BITRATE:
       x264->params.rc.i_bitrate = g_value_get_int (val);
