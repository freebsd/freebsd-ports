--- setup.py.orig	2021-09-04 19:49:01.514046000 -0500
+++ setup.py	2021-09-04 20:24:10.187804000 -0500
@@ -2,7 +2,7 @@
 from setuptools import setup
 
 packages = \
-['ospd', 'ospd.command', 'tests', 'tests.command']
+['ospd', 'ospd.command']
 
 package_data = \
 {'': ['*']}
