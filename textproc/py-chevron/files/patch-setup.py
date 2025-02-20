--- setup.py.orig	2021-01-02 20:33:10 UTC
+++ setup.py
@@ -3,7 +3,7 @@ try:
 import chevron.metadata
 
 try:
-    from setuptools import setup
+    from setuptools import setup, find_packages
 except ImportError:
     from distutils.core import setup
 
