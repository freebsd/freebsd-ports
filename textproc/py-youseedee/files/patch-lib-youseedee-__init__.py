--- lib/youseedee/__init__.py.orig	2025-07-24 11:24:42 UTC
+++ lib/youseedee/__init__.py
@@ -38,7 +38,7 @@ def ucd_dir():
 
 def ucd_dir():
     """Return the directory where Unicode data is stored"""
-    return Path(platformdirs.user_cache_dir("youseedee", ensure_exists=True))
+    return "%%UCDDIR%%"
 
 
 def ensure_files():
