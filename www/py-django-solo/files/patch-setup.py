Import internal "os" module to avoid errors during configuration phase.

--- setup.py.orig	2020-05-04 08:55:04 UTC
+++ setup.py
@@ -1,5 +1,6 @@
 from setuptools import setup, find_packages
 
+import os
 import solo
 
 README = os.path.join(os.path.dirname(__file__), 'README.rst')
