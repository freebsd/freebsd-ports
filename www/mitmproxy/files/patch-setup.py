--- setup.py.orig	2014-02-26 19:33:21.000000000 +0000
+++ setup.py	2014-06-06 06:28:44.000000000 +0100
@@ -1,4 +1,5 @@
 from distutils.core import setup
+from setuptools import setup
 import fnmatch, os.path
 from libmproxy import version
 
@@ -98,13 +99,4 @@
             "Topic :: Internet :: Proxy Servers",
             "Topic :: Software Development :: Testing"
         ],
-        install_requires=[
-            "netlib>=%s"%version.MINORVERSION,
-            "urwid>=1.1",
-            "pyasn1>0.1.2",
-            "pyopenssl>=0.13",
-            "Pillow>=2.3.0,<2.4",
-            "lxml",
-            "flask"
-        ],
 )
