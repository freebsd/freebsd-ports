--- src/oterm/utils.py.orig	2020-02-02 00:00:00 UTC
+++ src/oterm/utils.py
@@ -1,4 +1,4 @@
-import sys
+import platform
 from importlib import metadata
 from pathlib import Path
 
@@ -59,12 +59,13 @@ def get_default_data_dir() -> Path:
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
 
 
