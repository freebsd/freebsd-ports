--- setup.py.orig	2024-10-26 19:40:19 UTC
+++ setup.py
@@ -29,7 +29,7 @@ import os
 # ===================================================================
 
 import os
-from setuptools import setup, find_packages
+from setuptools import setup, find_namespace_packages
 
 project_name = "pycryptodome-test-vectors"
 project_dir = "pycryptodome_test_vectors"
@@ -61,7 +61,7 @@ setup(
     author_email="helderijs@gmail.com",
     platforms='Posix; MacOS X; Windows',
     zip_safe=False,
-    packages=find_packages(),
+    packages=find_namespace_packages(),
     include_package_data=True,
     license="BSD, Apache",
     long_description=longdesc,
