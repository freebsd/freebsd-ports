--- tensorflow/tf_framework_version_script.lds.orig	2023-03-30 17:42:11.255357000 +0200
+++ tensorflow/tf_framework_version_script.lds	2023-03-30 17:42:18.431845000 +0200
@@ -3,9 +3,6 @@
   local:
     jpeg_*;
     jinit_*;
-    jdiv_round_up;
-    jround_up;
-    jzero_far;
     jcopy_*;
     jsimd_*;
     hwloc_*;
