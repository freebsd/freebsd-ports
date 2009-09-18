--- setup.py.orig
+++ setup.py
@@ -5,9 +5,6 @@
 #  This script is placed in the public domain.
 #
 
-import ez_setup
-ez_setup.use_setuptools()
-
 from setuptools import setup, find_packages
 
 #  Import to allow pertinent info to be extracted
