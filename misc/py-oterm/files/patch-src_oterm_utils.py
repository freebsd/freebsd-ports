--- src/oterm/utils.py.orig	2020-02-02 00:00:00 UTC
+++ src/oterm/utils.py
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
+        "Windows": home / "AppData/Roaming/oterm",
+        "Linux": home / ".local/share/oterm",
+        "FreeBSD": home / ".local/share/oterm",
+        "Darwin": home / "Library/Application Support/oterm",
     }
 
-    data_path = system_paths[sys.platform]
+    data_path = system_paths[platform.system()]
     return data_path
 
 
