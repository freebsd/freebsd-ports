--- rpy/situation.py.orig	2019-05-05 16:29:19 UTC
+++ rpy/situation.py
@@ -63,7 +63,7 @@ def r_home_from_registry():
 
 def get_rlib_path(r_home: str, system: str) -> str:
     """Get the path for the R shared library."""
-    if system == 'Linux':
+    if system == 'FreeBSD' or system == 'Linux':
         lib_path = os.path.join(r_home, 'lib', 'libR.so')
     elif system == 'Darwin':
         lib_path = os.path.join(r_home, 'lib', 'libR.dylib')
