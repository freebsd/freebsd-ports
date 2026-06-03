--- third_party/xla/third_party/riegeli/workspace.bzl.orig	2026-03-04 21:33:50 UTC
+++ third_party/xla/third_party/riegeli/workspace.bzl
@@ -8,4 +8,5 @@ def repo():
         sha256 = "f63337f63f794ba9dc7dd281b20af3d036dfe0c1a5a4b7b8dc20b39f7e323b97",
         strip_prefix = "riegeli-9f2744dc23e81d84c02f6f51244e9e9bb9802d57",
         urls = tf_mirror_urls("https://github.com/google/riegeli/archive/9f2744dc23e81d84c02f6f51244e9e9bb9802d57.tar.gz"),
+        patch_file = ["//third_party:riegeli-xopen-source.patch"],
     )
