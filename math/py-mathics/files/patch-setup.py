--- setup.py.orig	2023-07-25 13:04:43 UTC
+++ setup.py
@@ -64,7 +64,7 @@ elif sys.version_info[:2] == (3, 6):
         sys.exit(-1)
 else:
     INSTALL_REQUIRES += [
-        "numpy<1.25",
+        "numpy<=1.25",
         "llvmlite",
         "sympy>=1.8",
         "pillow >= 9.2",
