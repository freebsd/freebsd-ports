--- third_party/xla/third_party/xnnpack/workspace.bzl.orig	2026-03-04 21:33:50 UTC
+++ third_party/xla/third_party/xnnpack/workspace.bzl
@@ -9,6 +9,9 @@ def repo():
         sha256 = "44bf8a258cfd0d7b500b6058a2bb5c7387c8cebba295cfca985a68d16513f7c8",
         strip_prefix = "XNNPACK-25b42dfddb0ee22170d73ff0d4b333ea1e6edfeb",
         urls = tf_mirror_urls("https://github.com/google/XNNPACK/archive/25b42dfddb0ee22170d73ff0d4b333ea1e6edfeb.zip"),
-        patch_file = ["//third_party/xnnpack:layering_check_fix.patch"],
+        patch_file = [
+            "//third_party/xnnpack:layering_check_fix.patch",
+            "//third_party/xnnpack:freebsd_mmap.patch",
+        ],
     )
     # LINT.ThenChange(//tensorflow/lite/tools/cmake/modules/xnnpack.cmake)
