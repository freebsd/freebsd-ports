--- comfy_cli/standalone.py.orig	2026-04-12 14:28:25 UTC
+++ comfy_cli/standalone.py
@@ -69,6 +69,11 @@ def download_standalone_python(
     https://gregoryszorc.com/docs/python-build-standalone/main/"""
     platform = get_os() if platform is None else platform
     proc = get_proc() if proc is None else proc
+    if (platform, proc) not in _platform_targets:
+        raise NotImplementedError(
+            f"Standalone Python download is not supported on {platform.value}/{proc.value}. "
+            "The python-build-standalone project does not provide builds for this platform."
+        )
     target = _platform_targets[(platform, proc)]
 
     if tag == "latest":
