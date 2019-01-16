--- wml_backend/p2_mp4h/src/builtin.c.orig 2018-12-24 13:19:13 UTC
+++ wml_backend/p2_mp4h/src/builtin.c
@@ -1069,10 +1069,13 @@
 static void
 mp4h_bp_mp4h_output_radix (MP4H_BUILTIN_ARGS)
 {
+  long int temp;
+
   if (bad_argc (argv[0], argc, 0, 2))
     return;
 
-  safe_strtol (ARG (0), ARG (1), (long int *) &output_radix);
+  safe_strtol (ARG (0), ARG (1), &temp);
+  output_radix = temp;
 }
 
 static void
