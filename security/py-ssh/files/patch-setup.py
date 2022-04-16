--- setup.py.orig	2012-09-14 19:01:37 UTC
+++ setup.py
@@ -38,7 +38,6 @@ import sys
 try:
     from setuptools import setup
     kw = {
-        'install_requires': 'pycrypto >= 2.1, != 2.4',
     }
 except ImportError:
     from distutils.core import setup
