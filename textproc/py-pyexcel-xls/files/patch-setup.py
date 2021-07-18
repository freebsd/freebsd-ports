--- setup.py.orig	2020-12-12 22:34:25 UTC
+++ setup.py
@@ -69,7 +69,7 @@ PYTHON_REQUIRES = ">=3.6"
 
 INSTALL_REQUIRES = [
     "pyexcel-io>=0.6.2",
-    "xlrd<2",
+    "xlrd",
     "xlwt",
 ]
 SETUP_COMMANDS = {}
