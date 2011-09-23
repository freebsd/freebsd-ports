--- setup.py.orig	2011-07-09 02:49:21.000000000 +0800
+++ setup.py	2011-09-24 00:26:44.327716441 +0800
@@ -5,10 +5,7 @@
 
 import sys
 import os
-try:
-    from setuptools import setup, Extension
-except ImportError:
-    from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 
 __ver__ = "0.3.0"
 
