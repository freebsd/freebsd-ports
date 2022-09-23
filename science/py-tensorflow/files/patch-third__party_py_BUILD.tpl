--- third_party/py/BUILD.tpl.orig	2022-09-07 10:53:01 UTC
+++ third_party/py/BUILD.tpl
@@ -9,12 +9,14 @@ load("@bazel_tools//tools/python:toolchain.bzl", "py_r
 py_runtime(
     name = "py2_runtime",
     interpreter_path = "%{PYTHON_BIN_PATH}",
+    stub_shebang = "#!%{PYTHON_BIN_PATH}",
     python_version = "PY2",
 )
 
 py_runtime(
     name = "py3_runtime",
     interpreter_path = "%{PYTHON_BIN_PATH}",
+    stub_shebang = "#!%{PYTHON_BIN_PATH}",
     python_version = "PY3",
 )
 
