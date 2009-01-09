--- setup.py.orig	2009-01-07 13:42:10.000000000 +0100
+++ setup.py	2009-01-07 13:42:27.000000000 +0100
@@ -0,0 +1,16 @@
+#!/usr/bin/python
+
+import glob
+import os
+import sys
+from distutils.core import setup
+
+setup(name="pyclamd",
+      version="0.1.1",
+      description="Python ClamD module.",
+      author="Alexandre Norman",
+      author_email="norman@xael.org",
+      url="http://xael.org/norman/python/pyclamd/",
+      license="GPL",
+      packages=['']
+     )
