--- rpy2/situation.py.orig	2019-09-27 19:59:40 UTC
+++ rpy2/situation.py
@@ -90,7 +90,7 @@ def r_home_from_registry() -> Optional[s
 
 def get_rlib_path(r_home: str, system: str) -> str:
     """Get the path for the R shared library."""
-    if system == 'Linux':
+    if system == 'FreeBSD' or system == 'Linux':
         lib_path = os.path.join(r_home, 'lib', 'libR.so')
     elif system == 'Darwin':
         lib_path = os.path.join(r_home, 'lib', 'libR.dylib')
