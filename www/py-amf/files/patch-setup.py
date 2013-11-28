--- ./setup.py.orig	2013-11-27 16:59:40.606322333 -0200
+++ ./setup.py	2013-11-27 17:00:06.922319988 -0200
@@ -3,11 +3,6 @@
 # Copyright (c) The PyAMF Project.
 # See LICENSE.txt for details.
 
-from distribute_setup import use_setuptools
-
-# 15 seconds is far too long ....
-use_setuptools(download_delay=3)
-
 # import ordering is important
 import setupinfo
 from setuptools import setup, find_packages
