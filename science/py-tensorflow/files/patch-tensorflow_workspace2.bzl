--- tensorflow/workspace2.bzl.orig	2022-05-22 22:28:22 UTC
+++ tensorflow/workspace2.bzl
@@ -137,6 +137,7 @@ def _tf_repositories():
         name = "XNNPACK",
         sha256 = "7e9ad45391e5158fd00e816022bda21d54a6180788af7c455c864a78cee252c6",
         strip_prefix = "XNNPACK-11b2812d64e49bab9b6c489f79067fc94e69db9f",
+        patch_file=["//third_party:add-default-option.patch"],
         urls = tf_mirror_urls("https://github.com/google/XNNPACK/archive/11b2812d64e49bab9b6c489f79067fc94e69db9f.zip"),
     )
     # LINT.ThenChange(//tensorflow/lite/tools/cmake/modules/xnnpack.cmake)
