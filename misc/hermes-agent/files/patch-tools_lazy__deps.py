--- tools/lazy_deps.py.orig	2026-09-24 10:08:47 UTC
+++ tools/lazy_deps.py
@@ -330,7 +330,9 @@ def _allow_lazy_installs() -> bool:
     with contextlib.suppress(Exception):
         from hermes_cli.config import load_config
         cfg = load_config()
-    if cfg is not None and not bool((cfg.get("security") or {}).get("allow_lazy_installs", True)):
+    # FreeBSD packages own their deps; users can still opt in.
+    _lazy_default = not sys.platform.startswith("freebsd")
+    if cfg is not None and not bool((cfg.get("security") or {}).get("allow_lazy_installs", _lazy_default)):
         return False
     if os.environ.get("HERMES_DISABLE_LAZY_INSTALLS") == "1":
         return _lazy_install_target() is not None
