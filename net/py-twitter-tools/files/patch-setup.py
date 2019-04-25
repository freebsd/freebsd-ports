# Fix UnicodeDecodeError: 'ascii' codec can't decode error

--- setup.py.orig	2019-04-25 10:41:18 UTC
+++ setup.py
@@ -1,11 +1,7 @@
 from setuptools import setup, find_packages
 import sys, os
 
-try:
-    import pypandoc
-    long_description = pypandoc.convert('README', 'rst', format='md')
-except ImportError:
-    long_description = open('./README', 'r').read()
+long_description = open('./README', 'rb').read().decode("utf-8")
 
 version = '1.18.0'
 
