--- setup.py.orig	Tue May 22 05:49:43 2007
+++ setup.py	Tue May 22 05:49:52 2007
@@ -33,14 +33,8 @@
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
+from distutils.core import setup
+kw = {}
     
 if sys.platform == 'darwin':
 	import setup_helper
