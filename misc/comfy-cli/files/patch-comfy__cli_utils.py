--- comfy_cli/utils.py.orig	2026-04-12 14:28:25 UTC
+++ comfy_cli/utils.py
@@ -49,6 +49,8 @@ def get_os():
         return OS.WINDOWS
     elif platform_system == "linux":
         return OS.LINUX
+    elif platform_system == "freebsd":
+        return OS.FREEBSD
     else:
         raise ValueError(f"Running on unsupported os {platform.system()}")
 
@@ -57,6 +59,8 @@ def get_proc():
     proc = platform.machine()
 
     if proc == "x86_64" or proc == "AMD64":
+        return PROC.X86_64
+    elif proc == "amd64":
         return PROC.X86_64
     elif "arm" in proc:
         return PROC.ARM
