--- setup.py.orig	2026-11-06 12:13:02 UTC
+++ setup.py
@@ -0,0 +1,9 @@
+from setuptools import Extension, setup
+
+setup(ext_modules=[
+    Extension(
+        "munkres._lapc",
+        ["src/munkres/_native/lapmodule.c"],
+        optional=True,
+    ),
+])
