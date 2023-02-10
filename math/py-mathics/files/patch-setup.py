--- setup.py.orig	2023-01-20 17:32:12 UTC
+++ setup.py
@@ -57,7 +57,7 @@ elif sys.version_info[:2] == (3, 6):
 elif sys.version_info[:2] == (3, 7):
     INSTALL_REQUIRES += ["numpy<1.22", "llvmlite", "sympy>=1.8, < 1.11"]
 else:
-    INSTALL_REQUIRES += ["numpy", "llvmlite", "sympy>=1.8, < 1.11"]
+    INSTALL_REQUIRES += ["numpy", "llvmlite", "sympy>=1.8, < 1.11.2"]
 
 if not is_PyPy:
     INSTALL_REQUIRES += ["recordclass"]
