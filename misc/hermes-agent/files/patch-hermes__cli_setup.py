--- hermes_cli/setup.py.orig	2026-05-16 09:59:15 UTC
+++ hermes_cli/setup.py	2026-05-19 11:15:38.531786000 +0200
@@ -2547,11 +2547,13 @@
         _is_linux = _platform.system() == "Linux"
         _is_macos = _platform.system() == "Darwin"
         _is_windows = _platform.system() == "Windows"
+        _is_freebsd = _platform.system() == "FreeBSD"
 
         from hermes_cli.gateway import (
             _is_service_installed,
             _is_service_running,
             supports_systemd_services,
+            supports_freebsd_rc,
             has_conflicting_systemd_units,
             has_legacy_hermes_units,
             install_linux_gateway_from_setup,
@@ -2562,6 +2564,9 @@
             launchd_install,
             launchd_start,
             launchd_restart,
+            freebsd_rc_install,
+            freebsd_rc_start,
+            freebsd_rc_restart,
             UserSystemdUnavailableError,
             SystemScopeRequiresRootError,
             _system_scope_wizard_would_need_root,
@@ -2571,7 +2576,8 @@
         service_installed = _is_service_installed()
         service_running = _is_service_running()
         supports_systemd = supports_systemd_services()
-        supports_service_manager = supports_systemd or _is_macos or _is_windows
+        supports_freebsd = supports_freebsd_rc()
+        supports_service_manager = supports_systemd or _is_macos or _is_windows or supports_freebsd
 
         print()
         if supports_systemd and has_conflicting_systemd_units():
@@ -2589,6 +2595,8 @@
                 try:
                     if supports_systemd:
                         systemd_restart()
+                    elif supports_freebsd:
+                        freebsd_rc_restart()
                     elif _is_macos:
                         launchd_restart()
                     elif _is_windows:
@@ -2614,6 +2622,8 @@
                 try:
                     if supports_systemd:
                         systemd_start()
+                    elif supports_freebsd:
+                        freebsd_rc_start()
                     elif _is_macos:
                         launchd_start()
                     elif _is_windows:
@@ -2631,6 +2641,8 @@
         elif supports_service_manager:
             if supports_systemd:
                 svc_name = "systemd"
+            elif supports_freebsd:
+                svc_name = "FreeBSD rc.d"
             elif _is_macos:
                 svc_name = "launchd"
             else:
@@ -2645,6 +2657,9 @@
                     started_inline = False
                     if supports_systemd:
                         installed_scope, did_install = install_linux_gateway_from_setup(force=False)
+                    elif supports_freebsd:
+                        freebsd_rc_install(force=False)
+                        did_install = True
                     elif _is_macos:
                         launchd_install(force=False)
                         did_install = True
@@ -2662,6 +2677,8 @@
                         try:
                             if supports_systemd:
                                 systemd_start(system=installed_scope == "system")
+                            elif supports_freebsd:
+                                freebsd_rc_start()
                             elif _is_macos:
                                 launchd_start()
                         except UserSystemdUnavailableError as e:
@@ -2680,6 +2697,8 @@
                 print_info("  You can install later: hermes gateway install")
                 if supports_systemd:
                     print_info("  Or as a boot-time service: sudo hermes gateway install --system")
+                elif supports_freebsd:
+                    print_info("  (FreeBSD rc.d install runs sysrc + service start with sudo.)")
                 print_info("  Or run in foreground:  hermes gateway")
         else:
             from hermes_constants import is_container
