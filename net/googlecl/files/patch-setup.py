--- ./setup.py.orig	2010-12-11 00:04:45.000000000 +0100
+++ ./setup.py	2010-12-11 00:04:57.000000000 +0100
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
