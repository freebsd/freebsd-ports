--- pulp/apis/core.py.orig2025-04-25 18:37:16 UTC
+++ pulp/apis/core.py
@@ -42,6 +42,8 @@ def get_operating_system():
         return "win"
     if sys.platform in ["darwin"]:
         return "osx"
+    if sys.platform in ["freebsd"]:
+        return "freebsd"
     return "linux"
