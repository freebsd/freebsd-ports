-- Add FreeBSD support to get_lib_pattern function.
-- FreeBSD uses .so files like Linux, so we add freebsd case.
--- setup.py.orig	2024-08-29 00:00:00 UTC
+++ setup.py
@@ -42,6 +42,8 @@ def get_lib_pattern(lib_name):
     lib_pattern = f"lib{lib_name}_*.so"
     elif sys.platform.startswith("darwin"):
         lib_pattern = f"lib{lib_name}_*.dylib"
+    elif sys.platform.startswith("freebsd"):
+        lib_pattern = f"lib{lib_name}_*.so"
     elif sys.platform.startswith("win"):
         lib_pattern = f"{lib_name}_*.dll"
     else:
