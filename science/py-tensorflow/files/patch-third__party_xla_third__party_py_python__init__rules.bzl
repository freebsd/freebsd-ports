--- third_party/xla/third_party/py/python_init_rules.bzl.orig	2026-03-04 21:33:50 UTC
+++ third_party/xla/third_party/py/python_init_rules.bzl
@@ -22,7 +22,7 @@ def python_init_rules(extra_patches = []):
 
     tf_http_archive(
         name = "com_google_protobuf",
-        patch_file = ["@xla//third_party/protobuf:protobuf.patch"],
+        patch_file = ["@xla//third_party/protobuf:protobuf.patch", "@xla//third_party/protobuf:freebsd_upb.patch"],
         sha256 = "6e09bbc950ba60c3a7b30280210cd285af8d7d8ed5e0a6ed101c72aff22e8d88",
         strip_prefix = "protobuf-6.31.1",
         urls = tf_mirror_urls("https://github.com/protocolbuffers/protobuf/archive/refs/tags/v6.31.1.zip"),
@@ -41,5 +41,6 @@ def python_init_rules(extra_patches = []):
             "@xla//third_party/py:rules_python_pip_version.patch",
             "@xla//third_party/py:rules_python_freethreaded.patch",
             "@xla//third_party/py:rules_python_versions.patch",
+            "@xla//third_party/py:rules_python_freebsd.patch",
         ] + extra_patches,
     )
