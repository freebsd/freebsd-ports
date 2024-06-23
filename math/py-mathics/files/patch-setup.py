--- setup.py.orig	2024-06-23 13:56:36 UTC
+++ setup.py
@@ -65,7 +65,7 @@ else:
         sys.exit(-1)
 else:
     INSTALL_REQUIRES += [
-        "numpy<1.25",
+        "numpy<1.27",
         "llvmlite",
         "sympy>=1.8",
         "pillow >= 9.2",
