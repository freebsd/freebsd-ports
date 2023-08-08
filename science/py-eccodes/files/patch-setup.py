--- setup.py.orig	2023-07-11 10:42:35 UTC
+++ setup.py
@@ -37,12 +37,6 @@ def parse_version_from(path):
 
 
 install_requires = ["numpy"]
-if sys.version_info < (3, 7):
-    install_requires = ["numpy<1.20"]
-elif sys.version_info < (3, 8):
-    install_requires = ["numpy<1.22"]
-elif sys.version_info < (3, 9):
-    install_requires = ["numpy<1.25"]
 
 install_requires += ["attrs", "cffi", "findlibs"]
 
