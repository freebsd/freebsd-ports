--- setup.py.orig	Mon Aug 21 19:21:34 2006
+++ setup.py	Mon Aug 21 19:22:15 2006
@@ -32,14 +32,8 @@
 #import ez_setup
 #ez_setup.use_setuptools()
 
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
 
 setup(name = "paramiko",
       version = "1.6.2",
