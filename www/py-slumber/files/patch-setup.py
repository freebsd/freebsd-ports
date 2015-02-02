--- setup.py.orig	2015-01-27 02:55:28 UTC
+++ setup.py
@@ -2,7 +2,7 @@ import os
 from setuptools import setup
 
 install_requires = ["requests"]
-tests_require = ["mock"]
+tests_require = ["mock", "unittest2"]
 
 base_dir = os.path.dirname(os.path.abspath(__file__))
 
