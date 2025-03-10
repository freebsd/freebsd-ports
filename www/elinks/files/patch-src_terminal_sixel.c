--- src/terminal/sixel.c.orig	2024-10-05 06:29:15 UTC
+++ src/terminal/sixel.c
@@ -83,7 +83,7 @@ struct sixel_encoder {
     int macro_number;
     int penetrate_multiplexer;
     int encode_policy;
-    int ormode;
+//    int ormode;
     int pipe_mode;
     int verbose;
     int has_gri_arg_limit;
@@ -733,7 +733,7 @@ sixel_encoder_encode_frame(
     sixel_output_set_penetrate_multiplexer(
         output, encoder->penetrate_multiplexer);
     sixel_output_set_encode_policy(output, encoder->encode_policy);
-    sixel_output_set_ormode(output, encoder->ormode);
+//    sixel_output_set_ormode(output, encoder->ormode);
 
 #if 0
     if (sixel_frame_get_multiframe(frame) && !encoder->fstatic) {
