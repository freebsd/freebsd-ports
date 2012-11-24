--- setup.py.orig	2012-04-09 11:55:00.000000000 +0800
+++ setup.py	2012-11-08 01:43:57.000000000 +0800
@@ -1,4 +1,5 @@
 from distutils.core import setup
+from setuptools import setup
 import fnmatch, os.path
 from libmproxy import version
 
@@ -92,5 +93,4 @@
             "Topic :: Internet :: Proxy Servers",
             "Topic :: Software Development :: Testing"
         ],
-        install_requires=['urwid>=1.0', 'pyasn1', 'pyopenssl>=0.12', "PIL", "lxml"],
 )
