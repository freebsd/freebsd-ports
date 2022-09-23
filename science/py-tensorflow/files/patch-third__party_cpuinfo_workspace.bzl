--- third_party/cpuinfo/workspace.bzl.orig	2022-08-29 16:23:14 UTC
+++ third_party/cpuinfo/workspace.bzl
@@ -8,5 +8,6 @@ def repo():
         strip_prefix = "cpuinfo-5916273f79a21551890fd3d56fc5375a78d1598d",
         sha256 = "2a160c527d3c58085ce260f34f9e2b161adc009b34186a2baf24e74376e89e6d",
         urls = tf_mirror_urls("https://github.com/pytorch/cpuinfo/archive/5916273f79a21551890fd3d56fc5375a78d1598d.zip"),
+	patch_file = ["//third_party:fix_cpuinfo.patch"],
         build_file = "//third_party/cpuinfo:cpuinfo.BUILD",
     )
