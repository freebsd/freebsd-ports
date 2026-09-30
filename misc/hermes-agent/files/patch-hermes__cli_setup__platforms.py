--- hermes_cli/setup_platforms.py.orig	2026-09-24 10:08:47 UTC
+++ hermes_cli/setup_platforms.py
@@ -290,6 +290,7 @@ def _restart_running_gateway(any_messaging: bool, supp
     from hermes_cli.gateway import (
         systemd_restart, launchd_restart, UserSystemdUnavailableError, SystemScopeRequiresRootError,
         _system_scope_wizard_would_need_root, _print_system_scope_remediation,
+        supports_freebsd_rc, freebsd_rc_restart,
     )
     import platform as _platform
     if supports_systemd and _system_scope_wizard_would_need_root():
@@ -300,6 +301,8 @@ def _restart_running_gateway(any_messaging: bool, supp
     try:
         if supports_systemd:
             systemd_restart()
+        elif supports_freebsd_rc():
+            freebsd_rc_restart()
         elif _platform.system() == "Darwin":
             launchd_restart()
         elif _platform.system() == "Windows":
