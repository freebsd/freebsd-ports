--- third_party/systemlibs/functools32.BUILD.orig	2021-07-08 13:17:43 UTC
+++ third_party/systemlibs/functools32.BUILD
@@ -0,0 +1,15 @@
+# Description:
+#   functools32 provides a backport of the functools module for Python 2.
+
+licenses(["notice"])  # Python 2.0
+
+package(default_visibility = ["//visibility:public"])
+
+filegroup(
+    name = "LICENSE",
+)
+
+py_library(
+    name = "functools32",
+    srcs_version = "PY2AND3",
+)
