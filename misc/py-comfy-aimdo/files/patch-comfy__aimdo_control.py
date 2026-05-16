-- Add FreeBSD support for loading the aimdo shared library.
-- FreeBSD uses .so shared libraries like Linux, with the same RTLD_DEEPBIND mode.
--- comfy_aimdo/control.py.orig	2026-05-16 19:21:31 UTC
+++ comfy_aimdo/control.py
@@ -55,7 +55,7 @@ def init(implementation: str | None = None):
         if system == "Windows":
             ext = "dll"
             mode = 0
-        elif system == "Linux":
+        elif system in ("Linux", "FreeBSD"):
             ext = "so"
             mode = 258
         else:
