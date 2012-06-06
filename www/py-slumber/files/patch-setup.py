--- ./setup.py.orig	2012-04-16 21:56:18.000000000 +1000
+++ ./setup.py	2012-06-02 20:40:02.000000000 +1000
@@ -1,5 +1,5 @@
 import os.path
-from setuptools import setup, find_packages
+from distutils.core import setup
 import sys
 
 install_requires = ["requests"]
@@ -20,7 +20,7 @@
     url = "http://slumber.in/",
     author = "Donald Stufft",
     author_email = "donald.stufft@gmail.com",
-    packages = find_packages(),
+    packages = ["slumber"],
     zip_safe = False,
     install_requires = install_requires,
     test_suite = "tests.get_tests",
