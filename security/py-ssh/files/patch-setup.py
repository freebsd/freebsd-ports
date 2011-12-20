--- setup.py.orig	2011-12-20 14:19:49.418637581 +0800
+++ setup.py	2011-12-20 14:20:31.345637126 +0800
@@ -38,7 +38,6 @@
 try:
     from setuptools import setup
     kw = {
-        'install_requires': 'pycrypto >= 2.1, != 2.4',
     }
 except ImportError:
     from distutils.core import setup
