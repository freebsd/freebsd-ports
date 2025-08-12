--- setup.py.orig	2025-07-25 10:03:25 UTC
+++ setup.py
@@ -90,7 +90,6 @@ install_requires += [
     "attrs",
     "cffi",
     "findlibs",
-    "eccodeslib;platform_system!='Windows'",
 ]
 
 setuptools.setup(
