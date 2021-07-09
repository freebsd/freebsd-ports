--- tensorflow/workspace.bzl.orig	2021-07-08 11:05:27 UTC
+++ tensorflow/workspace.bzl
@@ -324,6 +324,7 @@ def tf_repositories(path_prefix = "", tf_repo_name = "
         build_file = clean_dep("//third_party:functools32.BUILD"),
         sha256 = "f6253dfbe0538ad2e387bd8fdfd9293c925d63553f5813c4e587745416501e6d",
         strip_prefix = "functools32-3.2.3-2",
+        system_build_file = clean_dep("//third_party/systemlibs:functools32.BUILD"),
         urls = [
             "https://storage.googleapis.com/mirror.tensorflow.org/pypi.python.org/packages/c5/60/6ac26ad05857c601308d8fb9e87fa36d0ebf889423f47c3502ef034365db/functools32-3.2.3-2.tar.gz",
             "https://pypi.python.org/packages/c5/60/6ac26ad05857c601308d8fb9e87fa36d0ebf889423f47c3502ef034365db/functools32-3.2.3-2.tar.gz",
