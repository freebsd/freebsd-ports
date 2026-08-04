--- tools/lazy_deps.py.orig	2026-08-03 16:57:23 UTC
+++ tools/lazy_deps.py
@@ -514,7 +514,9 @@ def _allow_lazy_installs() -> bool:
         cfg = None
     if cfg is not None:
         sec = cfg.get("security") or {}
-        if not bool(sec.get("allow_lazy_installs", True)):
+        # FreeBSD packages own their deps; users can still opt in.
+        default = not sys.platform.startswith("freebsd")
+        if not bool(sec.get("allow_lazy_installs", default)):
             return False
 
     # (2) Sealed-venv env var: blocks ONLY when there is no safe durable
