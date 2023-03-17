--- setup.py.orig	2023-03-17 10:22:19 UTC
+++ setup.py
@@ -64,7 +64,7 @@ elif sys.version_info[:2] == (3, 6):
         sys.exit(-1)
 else:
     INSTALL_REQUIRES += [
-        "numpy<=1.24",
+        "numpy<=1.25",
         "llvmlite",
         "sympy>=1.8, < 1.12",
         "pillow >= 9.2",
