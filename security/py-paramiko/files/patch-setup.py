--- ./setup.py.orig	2010-02-24 21:06:37.000000000 +0100
+++ ./setup.py	2010-02-24 21:09:55.000000000 +0100
@@ -33,14 +33,9 @@
 #ez_setup.use_setuptools()
 
 import sys
-try:
-    from setuptools import setup
-    kw = {
-        'install_requires': 'pycrypto >= 1.9',
-    }
-except ImportError:
-    from distutils.core import setup
-    kw = {}
+
+from distutils.core import setup
+kw = {}
 
 if sys.platform == 'darwin':
 	import setup_helper
