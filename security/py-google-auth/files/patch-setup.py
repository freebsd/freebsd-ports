--- setup.py.orig	2021-11-01 20:33:09 UTC
+++ setup.py
@@ -20,7 +20,7 @@ from setuptools import setup
 
 
 DEPENDENCIES = (
-    "cachetools>=2.0.0,<5.0",
+    "cachetools>=2.0.0,<5.1",
     "pyasn1-modules>=0.2.1",
     # rsa==4.5 is the last version to support 2.7
     # https://github.com/sybrenstuvel/python-rsa/issues/152#issuecomment-643470233
