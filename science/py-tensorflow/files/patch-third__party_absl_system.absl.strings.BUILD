--- third_party/absl/system.absl.strings.BUILD.orig	2022-05-22 22:28:22 UTC
+++ third_party/absl/system.absl.strings.BUILD
@@ -4,7 +4,7 @@ package(default_visibility = ["//visibility:public"])
 
 cc_library(
     name = "strings",
-    linkopts = ["-labsl_strings"],
+    linkopts = ["-L%%LOCALBASE%%/lib", "-labsl_strings"],
     deps = [
         ":internal",
         "//absl/base",
@@ -26,7 +26,13 @@ cc_library(
 
 cc_library(
     name = "cord",
-    linkopts = ["-labsl_cord"],
+    linkopts = [
+        "-labsl_cord",
+        "-labsl_cord_internal",
+        "-labsl_cordz_functions",
+        "-labsl_cordz_handle",
+        "-labsl_cordz_info",
+        "-labsl_cordz_sample_token",],
     deps = [
         ":str_format",
         "//absl/container:compressed_tuple",
