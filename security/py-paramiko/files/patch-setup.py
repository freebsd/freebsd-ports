--- ./setup.py.orig	2014-05-20 15:06:31.000000000 +0200
+++ ./setup.py	2014-05-20 15:07:11.000000000 +0200
@@ -37,17 +37,8 @@
 #ez_setup.use_setuptools()
 
 import sys
-try:
-    from setuptools import setup
-    kw = {
-        'install_requires': [
-            'pycrypto >= 2.1, != 2.4',
-            'ecdsa',
-        ],
-    }
-except ImportError:
-    from distutils.core import setup
-    kw = {}
+from distutils.core import setup
+kw = {}
 
 if sys.platform == 'darwin':
     import setup_helper
