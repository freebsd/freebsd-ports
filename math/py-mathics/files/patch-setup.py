--- setup.py.orig	2021-07-31 19:47:09 UTC
+++ setup.py
@@ -105,7 +105,7 @@ else:
 # General Requirements
 INSTALL_REQUIRES += [
     "Mathics_Scanner>=1.2.1,<1.3.0",
-    "sympy>=1.8, <= 1.9dev",
+    "sympy>=1.8",
     "mpmath>=1.2.0",
     "numpy",
     "palettable",
