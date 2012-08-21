--- ./setup.py.orig	2012-08-20 21:53:58.000000000 +0200
+++ ./setup.py	2012-08-20 21:54:10.000000000 +0200
@@ -1,9 +1,5 @@
 # -*- coding: utf-8 -*-
 
-# Bootstrap installation of Distribute
-import distribute_setup
-distribute_setup.use_setuptools()
-
 from setuptools import setup, find_packages
 
 try:
@@ -43,5 +39,4 @@
     include_package_data=True,
     install_requires=requires,
     namespace_packages=['sphinxcontrib'],
-    py_modules = [ 'distribute_setup' ],
 )
