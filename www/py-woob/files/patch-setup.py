Exclude test files from being installed.
PR: 269003

--- setup.py.orig	2022-12-20 10:22:03 UTC
+++ setup.py
@@ -29,7 +29,7 @@ from setuptools import find_packages, setup
 
 
 def install_woob():
-    packages = set(find_packages(exclude=['modules', 'modules.*']))
+    packages = set(find_packages(exclude=['modules', 'modules.*', 'tests', 'tests.*']))
 
     data_files = [
         ('share/man/man1', glob.glob('man/*')),
