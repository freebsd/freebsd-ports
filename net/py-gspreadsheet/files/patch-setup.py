--- ./setup.py.orig	2013-10-29 16:50:19.871040385 +0200
+++ ./setup.py	2013-10-29 16:51:00.781040301 +0200
@@ -1,4 +1,4 @@
-from setuptools import setup
+from distutils.core import setup
 
 with open('README.rst') as f:
     long_description = f.read()
