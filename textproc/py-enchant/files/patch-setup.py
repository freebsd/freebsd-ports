--- setup.py	2010-02-23 01:51:41.000000000 +0100
+++ setup.py.port	2010-05-06 17:28:46.000000000 +0200
@@ -6,8 +6,8 @@
 #
 
 
-import distribute_setup
-distribute_setup.use_setuptools()
+#import distribute_setup
+#distribute_setup.use_setuptools()
 from setuptools import setup, find_packages, Extension
 
 import sys
