--- src/lib_ccx/ccx_decoders_708.h.orig	2020-08-28 16:03:38 UTC
+++ src/lib_ccx/ccx_decoders_708.h
@@ -368,7 +368,7 @@ void ccx_dtvcc_process_service_block(ccx_dtvcc_ctx *dt
 									 unsigned char *data,
 									 int data_length);
 
-ccx_dtvcc_pen_color ccx_dtvcc_default_pen_color;
-ccx_dtvcc_pen_attribs ccx_dtvcc_default_pen_attribs;
+extern ccx_dtvcc_pen_color ccx_dtvcc_default_pen_color;
+extern ccx_dtvcc_pen_attribs ccx_dtvcc_default_pen_attribs;
 
 #endif
