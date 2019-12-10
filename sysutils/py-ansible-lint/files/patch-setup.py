--- setup.py.orig	2019-12-09 07:04:35 UTC
+++ setup.py
@@ -0,0 +1,5 @@
+
+import setuptools
+if __name__ == "__main__":
+    setuptools.setup(use_scm_version=True)
+
