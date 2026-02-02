--- src/terminal/sixel.c.orig	2025-12-25 11:06:07 UTC
+++ src/terminal/sixel.c
@@ -86,7 +86,9 @@ struct sixel_encoder {
     int macro_number;
     int penetrate_multiplexer;
     int encode_policy;
+#ifdef SIXEL_OPTFLAG_ORMODE
     int ormode;
+#endif
     int pipe_mode;
     int verbose;
     int has_gri_arg_limit;
