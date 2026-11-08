--- pulp/apis/core.py.orig	2025-04-25 18:37:16 UTC
+++ pulp/apis/core.py
@@ -69,6 +69,8 @@ def get_operating_system() -> str:
     if sys.platform in ["win32", "cli"]:
         return "win"
     if sys.platform in ["darwin"]:
         return "osx"
+    if sys.platform in ["freebsd"]:
+        return "freebsd"
     return "linux"
