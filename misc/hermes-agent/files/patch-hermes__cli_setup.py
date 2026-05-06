--- hermes_cli/setup.py.orig	2026-05-06 08:29:55 UTC
+++ hermes_cli/setup.py
@@ -2409,11 +2409,13 @@ def setup_gateway(config: dict):
 
         _is_linux = _platform.system() == "Linux"
         _is_macos = _platform.system() == "Darwin"
+        _is_freebsd = _platform.system() == "FreeBSD"
 
         from hermes_cli.gateway import (
             _is_service_installed,
             _is_service_running,
             supports_systemd_services,
+            supports_freebsd_rc,
             has_conflicting_systemd_units,
             has_legacy_hermes_units,
             install_linux_gateway_from_setup,
@@ -2424,13 +2426,17 @@ def setup_gateway(config: dict):
             launchd_install,
             launchd_start,
             launchd_restart,
+            freebsd_rc_install,
+            freebsd_rc_start,
+            freebsd_rc_restart,
             UserSystemdUnavailableError,
         )
 
         service_installed = _is_service_installed()
         service_running = _is_service_running()
         supports_systemd = supports_systemd_services()
-        supports_service_manager = supports_systemd or _is_macos
+        supports_freebsd = supports_freebsd_rc()
+        supports_service_manager = supports_systemd or _is_macos or supports_freebsd
 
         print()
         if supports_systemd and has_conflicting_systemd_units():
@@ -2446,6 +2452,8 @@ def setup_gateway(config: dict):
                 try:
                     if supports_systemd:
                         systemd_restart()
+                    elif supports_freebsd:
+                        freebsd_rc_restart()
                     elif _is_macos:
                         launchd_restart()
                 except UserSystemdUnavailableError as e:
@@ -2459,6 +2467,8 @@ def setup_gateway(config: dict):
                 try:
                     if supports_systemd:
                         systemd_start()
+                    elif supports_freebsd:
+                        freebsd_rc_start()
                     elif _is_macos:
                         launchd_start()
                 except UserSystemdUnavailableError as e:
@@ -2468,7 +2478,12 @@ def setup_gateway(config: dict):
                 except Exception as e:
                     print_error(f"  Start failed: {e}")
         elif supports_service_manager:
-            svc_name = "systemd" if supports_systemd else "launchd"
+            if supports_systemd:
+                svc_name = "systemd"
+            elif supports_freebsd:
+                svc_name = "FreeBSD rc.d"
+            else:
+                svc_name = "launchd"
             if prompt_yes_no(
                 f"  Install the gateway as a {svc_name} service? (runs in background, starts on boot)",
                 True,
@@ -2478,6 +2493,9 @@ def setup_gateway(config: dict):
                     did_install = False
                     if supports_systemd:
                         installed_scope, did_install = install_linux_gateway_from_setup(force=False)
+                    elif supports_freebsd:
+                        freebsd_rc_install(force=False)
+                        did_install = True
                     else:
                         launchd_install(force=False)
                         did_install = True
@@ -2486,6 +2504,8 @@ def setup_gateway(config: dict):
                         try:
                             if supports_systemd:
                                 systemd_start(system=installed_scope == "system")
+                            elif supports_freebsd:
+                                freebsd_rc_start()
                             elif _is_macos:
                                 launchd_start()
                         except UserSystemdUnavailableError as e:
@@ -2501,6 +2521,8 @@ def setup_gateway(config: dict):
                 print_info("  You can install later: hermes gateway install")
                 if supports_systemd:
                     print_info("  Or as a boot-time service: sudo hermes gateway install --system")
+                elif supports_freebsd:
+                    print_info("  (FreeBSD rc.d install runs sysrc + service start with sudo.)")
                 print_info("  Or run in foreground:  hermes gateway")
         else:
             from hermes_constants import is_container
