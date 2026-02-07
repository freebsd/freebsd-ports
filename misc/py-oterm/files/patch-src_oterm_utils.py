--- src/oterm/utils.py.orig	2020-02-02 00:00:00 UTC
+++ src/oterm/utils.py
@@ -1,6 +1,7 @@ import sys
 import asyncio
 import os
 import sys
+import platform
 from collections.abc import Callable
 from functools import wraps
 from importlib import metadata
@@ -118,6 +119,7 @@ def get_default_data_dir() -> Path:
 
     system_paths = {
         "win32": home / "AppData/Roaming/oterm",
+        "FreeBSD": Path(os.getenv("XDG_DATA_HOME") or Path(home / ".local/share")),
         "linux": Path(os.getenv("XDG_DATA_HOME") or Path(home / ".local/share"))
         / "oterm",
         "darwin": Path(
@@ -126,7 +128,7 @@ def get_default_data_dir() -> Path:
         / "oterm",
     }
 
-    data_path = system_paths[sys.platform]
+    data_path = system_paths[platform.system()]
     return data_path
 
 
