--- tensorflow/tf_framework_version_script.lds.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/tf_framework_version_script.lds
@@ -3,9 +3,6 @@ VERS_1.0 {
   local:
     jpeg_*;
     jinit_*;
-    jdiv_round_up;
-    jround_up;
-    jzero_far;
     jcopy_*;
     jsimd_*;
     hwloc_*;
