--- torch/_inductor/cpp_builder.py.orig	2026-10-28 18:16:03 UTC
+++ torch/_inductor/cpp_builder.py
@@ -1481,6 +1481,10 @@ def _get_torch_related_args(
     if _IS_WINDOWS:
         libraries.append("sleef")
 
+    if sys.platform.startswith("freebsd"):
+        include_dirs.append("/usr/local/include")
+        libraries.append("sleef")
+
     return include_dirs, libraries_dirs, libraries
 
 
