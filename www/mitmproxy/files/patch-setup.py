--- setup.py.orig	2014-02-21 08:17:11.000000000 +0800
+++ setup.py	2014-02-21 08:19:43.000000000 +0800
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
-            "netlib>=%s"%version.VERSION,
-            "urwid>=1.1",
-            "pyasn1>0.1.2",
-            "pyopenssl>=0.13",
-            "Pillow>=2.3.0,<2.4",
-            "lxml",
-            "flask"
-        ],
 )
