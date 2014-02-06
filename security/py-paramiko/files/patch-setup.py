--- ./setup.py.orig	2014-02-06 14:49:52.000000000 +0100
+++ ./setup.py	2014-02-06 14:51:23.000000000 +0100
@@ -37,16 +37,8 @@
 #ez_setup.use_setuptools()
 
 import sys
-try:
-    from setuptools import setup
-    kw = {
-        'install_requires': ['pycrypto >= 2.1, != 2.4',
-                             'ecdsa',
-                             ],
-    }
-except ImportError:
-    from distutils.core import setup
-    kw = {}
+from distutils.core import setup
+kw = {}
 
 if sys.platform == 'darwin':
     import setup_helper
