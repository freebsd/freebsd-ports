--- third_party/xla/third_party/pthreadpool/workspace.bzl.orig	2026-03-04 21:33:50 UTC
+++ third_party/xla/third_party/pthreadpool/workspace.bzl
@@ -8,4 +8,7 @@ def repo():
         sha256 = "f602ab141bdc5d5872a79d6551e9063b5bfa7ad6ad60cceaa641de5c45c86d70",
         strip_prefix = "pthreadpool-0e6ca13779b57d397a5ba6bfdcaa8a275bc8ea2e",
         urls = tf_mirror_urls("https://github.com/google/pthreadpool/archive/0e6ca13779b57d397a5ba6bfdcaa8a275bc8ea2e.zip"),
+        patch_file = [
+            "@xla//third_party/pthreadpool:freebsd_alloca.patch",
+        ],
     )
