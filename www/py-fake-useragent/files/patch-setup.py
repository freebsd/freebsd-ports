--- setup.py.orig	2022-11-12 09:41:13 UTC
+++ setup.py
@@ -0,0 +1,3 @@
+import setuptools
+if __name__ == "__main__":
+    setuptools.setup(use_scm_version=False)
