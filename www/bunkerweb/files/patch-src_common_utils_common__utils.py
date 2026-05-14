--- src/common/utils/common_utils.py.orig	2026-05-28 20:12:40 UTC
+++ src/common/utils/common_utils.py
@@ -54,7 +54,7 @@ def get_version() -> str:
 
 
 def get_version() -> str:
-    return Path(sep, "usr", "share", "bunkerweb", "VERSION").read_text(encoding="utf-8").strip()
+    return Path(sep, "usr", "local", "share", "bunkerweb", "VERSION").read_text(encoding="utf-8").strip()
 
 
 def get_integration() -> str:
