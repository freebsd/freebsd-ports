--- setup.py.orig	2012-02-06 14:55:59.000000000 +0400
+++ setup.py	2012-08-09 14:41:28.000000000 +0400
@@ -19,9 +19,6 @@
 with open(version_file) as fh:
     nltk_version = fh.read().strip()
 
-import distribute_setup
-distribute_setup.use_setuptools()
-
 from setuptools import setup, find_packages
 
 #
