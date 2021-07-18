--- setup.py.orig	2021-03-29 20:04:36 UTC
+++ setup.py
@@ -20,7 +20,7 @@ from setuptools import setup
 
 TOOL_DEPENDENCIES = "click>=6.0.0"
 
-DEPENDENCIES = ("google-auth>=1.0.0", "requests-oauthlib>=0.7.0")
+DEPENDENCIES = ("google-auth>=1.0.0", "requests-oauthlib>=0")
 
 
 with io.open("README.rst", "r") as fh:
