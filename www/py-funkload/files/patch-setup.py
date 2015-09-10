--- setup.py.orig	2015-05-06 10:37:24 UTC
+++ setup.py
@@ -21,8 +21,6 @@
 """FunkLoad package setup
 
 """
-import ez_setup
-ez_setup.use_setuptools()
 from setuptools import setup, find_packages
 __version__ = '1.17.1'
 
@@ -30,7 +28,7 @@ setup(
     name="funkload",
     version=__version__,
     description="Functional and load web tester.",
-    long_description=''.join(open('README.txt').readlines()),
+    long_description='',
     author="Benoit Delbosc",
     author_email="bdelbosc@nuxeo.com",
     url="http://funkload.nuxeo.org/",
