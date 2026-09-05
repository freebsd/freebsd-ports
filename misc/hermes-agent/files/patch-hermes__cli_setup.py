--- hermes_cli/setup.py.orig	2026-08-31 19:29:27 UTC
+++ hermes_cli/setup.py
@@ -2350,9 +2350,11 @@ def setup_gateway(config: dict):
     from hermes_cli.gateway import (
         _is_service_running,
         supports_systemd_services,
+        supports_freebsd_rc,
         ensure_gateway_service,
         systemd_restart,
         launchd_restart,
+        freebsd_rc_restart,
         UserSystemdUnavailableError,
         SystemScopeRequiresRootError,
         _system_scope_wizard_would_need_root,
@@ -2363,6 +2365,7 @@ def setup_gateway(config: dict):
     _is_macos = _platform.system() == "Darwin"
     _is_windows = _platform.system() == "Windows"
     supports_systemd = supports_systemd_services()
+    supports_rc = supports_freebsd_rc()
 
     print()
     if _is_service_running():
@@ -2377,6 +2380,8 @@ def setup_gateway(config: dict):
             try:
                 if supports_systemd:
                     systemd_restart()
+                elif supports_rc:
+                    freebsd_rc_restart()
                 elif _is_macos:
                     launchd_restart()
                 elif _is_windows:
