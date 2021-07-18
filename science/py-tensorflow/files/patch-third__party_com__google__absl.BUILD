--- third_party/com_google_absl.BUILD.orig	2021-07-07 09:58:12 UTC
+++ third_party/com_google_absl.BUILD
@@ -2,4 +2,9 @@ package(default_visibility = ["//visibility:public"])
 
 licenses(["notice"])  # Apache
 
-exports_files(["LICENSE"])
+exports_files(["LICENSE", "absl"])
+
+cc_library(
+    name = "abslHeaders",
+    hdrs = glob(["*/*/*.h", "*/*/*.h"]),
+)
