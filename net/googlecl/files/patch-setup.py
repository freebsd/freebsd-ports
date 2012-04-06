--- ./setup.py.orig	2012-04-06 17:49:48.000000000 +0200
+++ ./setup.py	2012-04-06 17:49:57.000000000 +0200
@@ -14,10 +14,7 @@
 
 from __future__ import with_statement
 
-try:
-  from setuptools import setup
-except ImportError:
-  from distutils.core import setup
+from distutils.core import setup
 import os
 import shutil
 packages =['googlecl',
