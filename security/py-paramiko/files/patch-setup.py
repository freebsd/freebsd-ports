--- ./setup.py.orig	2012-10-03 11:45:35.000000000 +0200
+++ ./setup.py	2012-10-03 11:46:32.000000000 +0200
@@ -37,14 +37,8 @@
 #ez_setup.use_setuptools()
 
 import sys
-try:
-    from setuptools import setup
-    kw = {
-        'install_requires': 'pycrypto >= 2.1, != 2.4',
-    }
-except ImportError:
-    from distutils.core import setup
-    kw = {}
+from distutils.core import setup
+kw = {}
 
 if sys.platform == 'darwin':
     import setup_helper
