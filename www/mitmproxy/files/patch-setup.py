--- setup.py.orig	2013-07-23 03:08:39.785592808 +0800
+++ setup.py	2013-07-23 03:09:19.367592415 +0800
@@ -1,4 +1,5 @@
 from distutils.core import setup
+from setuptools import setup
 import fnmatch, os.path
 from libmproxy import version
 
@@ -92,13 +93,4 @@
             "Topic :: Internet :: Proxy Servers",
             "Topic :: Software Development :: Testing"
         ],
-        install_requires=[
-            "netlib>=%s"%version.VERSION,
-            "urwid>=1.1",
-            "pyasn1>0.1.2",
-            "pyopenssl>=0.13",
-            "PIL",
-            "lxml",
-            "flask"
-        ],
 )
