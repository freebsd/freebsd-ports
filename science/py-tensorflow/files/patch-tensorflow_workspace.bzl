--- tensorflow/workspace.bzl.orig	2021-01-04 20:18:42 UTC
+++ tensorflow/workspace.bzl
@@ -157,6 +157,7 @@ def tf_repositories(path_prefix = "", tf_repo_name = "
     tf_http_archive(
         name = "com_google_absl",
         build_file = clean_dep("//third_party:com_google_absl.BUILD"),
+        patch_file = clean_dep("//third_party:extra-patch-absl_base_internal_unscaledcycleclock.cc"),
         sha256 = "acd93f6baaedc4414ebd08b33bebca7c7a46888916101d8c0b8083573526d070",
         strip_prefix = "abseil-cpp-43ef2148c0936ebf7cb4be6b19927a9d9d145b8f",
         urls = [
@@ -324,6 +325,7 @@ def tf_repositories(path_prefix = "", tf_repo_name = "
         build_file = clean_dep("//third_party:functools32.BUILD"),
         sha256 = "f6253dfbe0538ad2e387bd8fdfd9293c925d63553f5813c4e587745416501e6d",
         strip_prefix = "functools32-3.2.3-2",
+        system_build_file = clean_dep("//third_party/systemlibs:functools32.BUILD"),
         urls = [
             "https://storage.googleapis.com/mirror.tensorflow.org/pypi.python.org/packages/c5/60/6ac26ad05857c601308d8fb9e87fa36d0ebf889423f47c3502ef034365db/functools32-3.2.3-2.tar.gz",
             "https://pypi.python.org/packages/c5/60/6ac26ad05857c601308d8fb9e87fa36d0ebf889423f47c3502ef034365db/functools32-3.2.3-2.tar.gz",
