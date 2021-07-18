--- setup.py.orig	2021-04-05 03:23:24 UTC
+++ setup.py
@@ -1,2 +1,4 @@
+# Upstream switched to PEP-517 packaging
 from setuptools import setup
-setup()
+if __name__ == "__main__":
+    setup(use_scm_version=True)
