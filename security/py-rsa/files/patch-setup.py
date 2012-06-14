--- ./setup.py.orig	2012-05-26 03:11:35.000000000 +1000
+++ ./setup.py	2012-05-26 03:11:46.000000000 +1000
@@ -1,9 +1,5 @@
 #!/usr/bin/env python
 
-# Ensure that a reasonably recent version of 'distribute' is installed.
-from distribute_setup import use_setuptools
-use_setuptools('0.6.10')
-
 from setuptools import setup
 
 import rsa
