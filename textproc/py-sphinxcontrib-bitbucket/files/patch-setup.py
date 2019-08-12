--- setup.py.orig	2011-04-24 16:19:59 UTC
+++ setup.py
@@ -1,9 +1,5 @@
 # -*- coding: utf-8 -*-
 
-# Bootstrap installation of Distribute
-import distribute_setup
-distribute_setup.use_setuptools()
-
 from setuptools import setup, find_packages
 
 try:
@@ -43,5 +39,4 @@ setup(
     include_package_data=True,
     install_requires=requires,
     namespace_packages=['sphinxcontrib'],
-    py_modules = [ 'distribute_setup' ],
 )
