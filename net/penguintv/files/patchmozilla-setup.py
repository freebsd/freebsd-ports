--- setup.py.orig	Tue May 16 07:18:29 2006
+++ setup.py	Tue May 16 07:20:03 2006
@@ -1,11 +1,4 @@
-try:
-	from Pyrex.Distutils import build_ext
-	BUILD_MOZ=True
-except:
-	print "pyrex not found, mozilla building disabled"
-	BUILD_MOZ=False
-
-
+BUILD_MOZ=False
 from distutils.core import setup
 from distutils.extension import Extension
 import sys,os
