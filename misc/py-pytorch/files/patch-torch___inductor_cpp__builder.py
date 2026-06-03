--- torch/_inductor/cpp_builder.py.orig	2026-05-13 17:40:44 UTC
+++ torch/_inductor/cpp_builder.py
@@ -1253,6 +1253,10 @@ def _get_torch_related_args(
     if _IS_WINDOWS:
         libraries.append("sleef")
 
+    if sys.platform.startswith("freebsd"):
+        include_dirs.append("/usr/local/include")
+        libraries.append("sleef")
+
     return include_dirs, libraries_dirs, libraries
 
 
