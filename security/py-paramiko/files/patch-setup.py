--- ./setup.py.orig	2011-05-31 12:57:26.000000000 +0200
+++ ./setup.py	2011-05-31 13:01:30.000000000 +0200
@@ -33,14 +33,9 @@
 #ez_setup.use_setuptools()
 
 import sys
-try:
-    from setuptools import setup
-    kw = {
-        'install_requires': 'pycrypto >= 2.1',
-    }
-except ImportError:
-    from distutils.core import setup
-    kw = {}
+
+from distutils.core import setup
+kw = {}
 
 if sys.platform == 'darwin':
 	import setup_helper
