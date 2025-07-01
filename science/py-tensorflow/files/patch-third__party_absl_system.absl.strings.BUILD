--- third_party/absl/system.absl.strings.BUILD.orig	2023-09-12 16:46:28 UTC
+++ third_party/absl/system.absl.strings.BUILD
@@ -26,7 +26,11 @@ cc_library(
 
 cc_library(
     name = "cord",
-    linkopts = ["-labsl_cord"],
+    linkopts = [
+        "-labsl_cord",
+        "-labsl_cord_internal",
+        "-labsl_cordz_info"
+    ],
     deps = [
         ":str_format",
         "//absl/container:compressed_tuple",
