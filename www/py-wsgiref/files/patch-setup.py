--- setup.py.orig	Thu Dec 21 21:11:56 2006
+++ setup.py	Thu Dec 21 21:15:05 2006
@@ -2,10 +2,7 @@
 
 """Distutils setup file"""
 
-import ez_setup
-ez_setup.use_setuptools()
-
-from setuptools import setup, find_packages
+from distutils.core import setup
 
 # Metadata
 PACKAGE_NAME = "wsgiref"
