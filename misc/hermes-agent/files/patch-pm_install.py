--- pm/install.py.orig	2026-11-16 19:28:45 UTC
+++ pm/install.py
@@ -199,7 +199,10 @@ def lazy_installs_allowed() -> bool:
         # The normal loader falls back to defaults on invalid YAML. A broken
         # security policy must not grant permission to acquire dependencies.
         require_readable_config_before_write()
-        return cfg_get(load_config_readonly(), "security", "allow_lazy_installs", default=True) is True
+        # FreeBSD packages own their deps; users can still opt in.
+        import sys
+        _default = not sys.platform.startswith("freebsd")
+        return cfg_get(load_config_readonly(), "security", "allow_lazy_installs", default=_default) is True
     except Exception:
         return False
 
