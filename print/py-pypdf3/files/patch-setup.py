--- setup.py.orig	2022-02-03 16:27:04 UTC
+++ setup.py
@@ -30,7 +30,7 @@ setup(
     raise RuntimeError("Unable to find version string in %s." % (VERSIONFILE))
 
 setup(
-        name="PyPDF3",
+        name="pypdf3",
         version=verstr,
         install_requires=['tqdm'],
         description="Pure Python PDF toolkit",
