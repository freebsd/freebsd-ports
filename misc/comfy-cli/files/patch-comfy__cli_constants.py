--- comfy_cli/constants.py.orig	2026-04-12 14:28:25 UTC
+++ comfy_cli/constants.py
@@ -6,6 +6,7 @@ class OS(str, Enum):
     WINDOWS = "windows"
     MACOS = "macos"
     LINUX = "linux"
+    FREEBSD = "freebsd"
 
 
 class PROC(str, Enum):
@@ -22,12 +23,14 @@ DEFAULT_COMFY_WORKSPACE = {
     OS.WINDOWS: os.path.join(os.path.expanduser("~"), "Documents", "comfy", "ComfyUI"),
     OS.MACOS: os.path.join(os.path.expanduser("~"), "Documents", "comfy", "ComfyUI"),
     OS.LINUX: os.path.join(os.path.expanduser("~"), "comfy", "ComfyUI"),
+    OS.FREEBSD: os.path.join(os.path.expanduser("~"), "comfy", "ComfyUI"),
 }
 
 DEFAULT_CONFIG = {
     OS.WINDOWS: os.path.join(os.path.expanduser("~"), "AppData", "Local", "comfy-cli"),
     OS.MACOS: os.path.join(os.path.expanduser("~"), "Library", "Application Support", "comfy-cli"),
     OS.LINUX: os.path.join(os.path.expanduser("~"), ".config", "comfy-cli"),
+    OS.FREEBSD: os.path.join(os.path.expanduser("~"), ".config", "comfy-cli"),
 }
 
 CONTEXT_KEY_WORKSPACE = "workspace"
