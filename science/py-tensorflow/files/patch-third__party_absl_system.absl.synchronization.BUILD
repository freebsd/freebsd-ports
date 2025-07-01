--- third_party/absl/system.absl.synchronization.BUILD.orig	2023-09-12 16:46:28 UTC
+++ third_party/absl/system.absl.synchronization.BUILD
@@ -17,13 +17,28 @@ cc_library(
 )
 
 cc_library(
+    name = "kernel_timeout_internal",
+    visibility = [
+    ],
+    deps = [
+        "//absl/base",
+        "//absl/base:config",
+        "//absl/base:core_headers",
+        "//absl/base:raw_logging_internal",
+        "//absl/time",
+    ],
+)
+
+cc_library(
     name = "synchronization",
     linkopts = [
         "-labsl_synchronization",
+        "-labsl_kernel_timeout_internal",
         "-pthread",
     ],
     deps = [
         ":graphcycles_internal",
+        ":kernel_timeout_internal",
         "//absl/base",
         "//absl/base:atomic_hook",
         "//absl/base:dynamic_annotations",
