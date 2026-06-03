--- tensorflow/workspace2.bzl.orig	2026-03-04 21:33:50 UTC
+++ tensorflow/workspace2.bzl
@@ -179,6 +179,7 @@ def _tf_repositories():
         sha256 = "44bf8a258cfd0d7b500b6058a2bb5c7387c8cebba295cfca985a68d16513f7c8",
         strip_prefix = "XNNPACK-25b42dfddb0ee22170d73ff0d4b333ea1e6edfeb",
         urls = tf_mirror_urls("https://github.com/google/XNNPACK/archive/25b42dfddb0ee22170d73ff0d4b333ea1e6edfeb.zip"),
+        patch_file = ["@xla//third_party/xnnpack:freebsd_mmap.patch"],
     )
     # LINT.ThenChange(//tensorflow/lite/tools/cmake/modules/xnnpack.cmake)
 
@@ -202,6 +203,7 @@ def _tf_repositories():
         name = "pthreadpool",
         sha256 = "f602ab141bdc5d5872a79d6551e9063b5bfa7ad6ad60cceaa641de5c45c86d70",
         strip_prefix = "pthreadpool-0e6ca13779b57d397a5ba6bfdcaa8a275bc8ea2e",
+        patch_file = ["@xla//third_party/pthreadpool:freebsd_alloca.patch"],
         urls = tf_mirror_urls("https://github.com/google/pthreadpool/archive/0e6ca13779b57d397a5ba6bfdcaa8a275bc8ea2e.zip"),
     )
     # LINT.ThenChange(//tensorflow/lite/cmake/DownloadPThreadPool.cmake)
@@ -210,7 +212,7 @@ def _tf_repositories():
         name = "cpuinfo",
         sha256 = "c0254ce97f7abc778dd2df0aaca1e0506dba1cd514fdb9fe88c07849393f8ef4",
         strip_prefix = "cpuinfo-8a9210069b5a37dd89ed118a783945502a30a4ae",
-        patch_file = ["//third_party/cpuinfo:cpuinfo_ppc64le_support.patch"],
+        patch_file = ["//third_party/cpuinfo:cpuinfo_ppc64le_support.patch", "//third_party/cpuinfo:cpuinfo_freebsd_alwayslink.patch"],
         urls = tf_mirror_urls("https://github.com/pytorch/cpuinfo/archive/8a9210069b5a37dd89ed118a783945502a30a4ae.zip"),
     )
 
@@ -474,6 +476,7 @@ def _tf_repositories():
         patch_file = [
             "@xla//third_party/grpc:grpc.patch",
+            "@xla//third_party/grpc:grpc_no_go.patch",
         ],
         urls = tf_mirror_urls("https://github.com/grpc/grpc/archive/refs/tags/v1.74.0.tar.gz"),
     )
