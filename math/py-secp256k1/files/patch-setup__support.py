--- setup_support.py.orig	2026-01-28 09:03:52 UTC
+++ setup_support.py
@@ -105,4 +105,4 @@ def has_system_lib():
     global _has_system_lib
     if _has_system_lib is None:
         _has_system_lib = _find_lib()
-    return False
+    return _has_system_lib
