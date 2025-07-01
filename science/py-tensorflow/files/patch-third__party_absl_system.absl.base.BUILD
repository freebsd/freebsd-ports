--- third_party/absl/system.absl.base.BUILD.orig	2023-09-12 16:46:28 UTC
+++ third_party/absl/system.absl.base.BUILD
@@ -17,7 +17,14 @@ cc_library(
 
 cc_library(
     name = "log_severity",
-    linkopts = ["-labsl_log_severity"],
+    linkopts = [
+        "-labsl_log_severity",
+        "-labsl_log_internal_check_op",
+        "-labsl_log_internal_conditions",
+        "-labsl_log_internal_message",
+        "-labsl_log_internal_nullguard",
+        "-labsl_vlog_config_internal",
+    ],
 )
 
 cc_library(
