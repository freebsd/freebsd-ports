--- setup.py.orig	2013-01-27 15:48:03 UTC
+++ setup.py
@@ -65,9 +65,13 @@ available.""")
 
 
 if Feature:
+    # Optional C extension module for speeding up Genshi:
+    # Not activated by default on:
+    # - PyPy (where it harms performance)
+    # - CPython >= 3.3 (the new Unicode C API is not supported yet)
     speedups = Feature(
         "optional C speed-enhancements",
-        standard = not is_pypy,
+        standard = not is_pypy and sys.version_info < (3, 3),
         ext_modules = [
             Extension('genshi._speedups', ['genshi/_speedups.c']),
         ],
