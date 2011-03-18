--- setup.py.orig	2011-02-12 23:12:29.000000000 +0800
+++ setup.py	2011-03-18 11:38:46.000000000 +0800
@@ -18,9 +18,9 @@
     raise Exception("Kombu requires Python 2.4 or higher.")
 
 try:
-    from setuptools import setup, Extension, Feature, find_packages
+    from setuptools import setup, Extension, Feature
 except ImportError:
-    from distutils.core import setup, Extension, find_packages
+    from distutils.core import setup, Extension
     Feature = None
 
 from distutils.command.install_data import install_data
