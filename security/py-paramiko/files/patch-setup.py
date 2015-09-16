--- setup.py.orig	2014-12-19 23:01:22 UTC
+++ setup.py
@@ -37,17 +37,9 @@ To install the `in-development version
 #ez_setup.use_setuptools()
 
 import sys
-try:
-    from setuptools import setup
-    kw = {
-        'install_requires': [
-            'pycrypto >= 2.1, != 2.4',
-            'ecdsa >= 0.11',
-        ],
-    }
-except ImportError:
-    from distutils.core import setup
-    kw = {}
+
+from distutils.core import setup
+kw = {}
 
 if sys.platform == 'darwin':
     import setup_helper
