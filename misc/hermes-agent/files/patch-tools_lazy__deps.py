--- tools/lazy_deps.py.orig	2026-08-31 19:29:27 UTC
+++ tools/lazy_deps.py
@@ -524,7 +524,9 @@ def _allow_lazy_installs() -> bool:
         cfg = None
     if cfg is not None:
         sec = cfg.get("security") or {}
-        if not bool(sec.get("allow_lazy_installs", True)):
+        # FreeBSD packages own their deps; users can still opt in.
+        default = not sys.platform.startswith("freebsd")
+        if not bool(sec.get("allow_lazy_installs", default)):
             return False
 
     # (2) Sealed-venv env var: blocks ONLY when there is no safe durable
