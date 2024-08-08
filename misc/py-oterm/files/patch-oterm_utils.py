--- oterm/utils.py.orig	2024-05-15 16:35:57 UTC
+++ oterm/utils.py
@@ -1,4 +1,4 @@
-import sys
+import platform
 from pathlib import Path
 
 
@@ -16,12 +16,13 @@ def get_default_data_dir() -> Path:
     home = Path.home()
 
     system_paths = {
-        "win32": home / "AppData/Roaming/oterm",
-        "linux": home / ".local/share/oterm",
-        "darwin": home / "Library/Application Support/oterm",
+        "Darwin": home / "Library/Application Support/oterm",
+        "FreeBSD": home / ".local/share/oterm",
+        "Linux": home / ".local/share/oterm",
+        "Windows": home / "AppData/Roaming/oterm",
     }
 
-    data_path = system_paths[sys.platform]
+    data_path = system_paths[platform.system()]
     return data_path
 
 
