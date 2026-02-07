--- tensorflow/workspace2.bzl.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/workspace2.bzl
@@ -145,6 +145,7 @@ def _tf_repositories():
         name = "XNNPACK",
         sha256 = "c979b62e8b77af60dfd7567f22ade20d5a9d4d0888f8a2d60d155fc0d31b22ab",
         strip_prefix = "XNNPACK-b9d4073a6913891ce9cbd8965c8d506075d2a45a",
+        patch_file=["//third_party:fix-xnnpack.patch"],
         urls = tf_mirror_urls("https://github.com/google/XNNPACK/archive/b9d4073a6913891ce9cbd8965c8d506075d2a45a.zip"),
     )
     # LINT.ThenChange(//tensorflow/lite/tools/cmake/modules/xnnpack.cmake)
@@ -165,9 +166,9 @@ def _tf_repositories():
 
     tf_http_archive(
         name = "cpuinfo",
-        strip_prefix = "cpuinfo-3dc310302210c1891ffcfb12ae67b11a3ad3a150",
-        sha256 = "ba668f9f8ea5b4890309b7db1ed2e152aaaf98af6f9a8a63dbe1b75c04e52cb9",
-        urls = tf_mirror_urls("https://github.com/pytorch/cpuinfo/archive/3dc310302210c1891ffcfb12ae67b11a3ad3a150.zip"),
+        strip_prefix = "cpuinfo-fa1c679da8d19e1d87f20175ae1ec10995cd3dd3",
+        sha256 = "2bf2b62eb86e2d2eaf862d0b9683a6c467a4d69fb2f7f1dc47c799809148608f",
+        urls = tf_mirror_urls("https://github.com/pytorch/cpuinfo/archive/fa1c679da8d19e1d87f20175ae1ec10995cd3dd3.zip"),
     )
 
     tf_http_archive(
@@ -875,7 +876,7 @@ def _tf_repositories():
         urls = tf_mirror_urls("https://github.com/pybind/pybind11_protobuf/archive/80f3440cd8fee124e077e2e47a8a17b78b451363.zip"),
         sha256 = "c7ab64b1ccf9a678694a89035a8c865a693e4e872803778f91f0965c2f281d78",
         strip_prefix = "pybind11_protobuf-80f3440cd8fee124e077e2e47a8a17b78b451363",
-        patch_file = ["//third_party/pybind11_protobuf:remove_license.patch"],
+        patch_file = ["//third_party/pybind11_protobuf:remove_license.patch","//third_party:fix-pybind11_protobuf.patch"],
     )
 
     tf_http_archive(
