--- setup.py.orig	2026-05-24 01:06:41 UTC
+++ setup.py
@@ -2,13 +2,11 @@
 
 """Setup script for the Python-PAM module distribution."""
 
-import distutils
-from distutils.core import setup
-from distutils.extension import Extension
+from setuptools import setup, Extension
 
 ext = Extension(
-    name="PAMmodule",
-    libraries=["pam","pam_misc"],
+    name="PAM",
+    libraries=["pam"],
     sources=["PAMmodule.c"]
 )
 ##print ext.__dict__; sys.exit(1)
