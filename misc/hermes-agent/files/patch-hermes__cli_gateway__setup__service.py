--- hermes_cli/gateway_setup_service.py.orig	2026-10-26 16:08:51 UTC
+++ hermes_cli/gateway_setup_service.py
@@ -55,7 +55,8 @@
         gw.print_info("Run hermes gateway run as the container main process; use a Docker restart policy for persistence.")
         return False
     supports_systemd = gw.supports_systemd_services()
-    if not (supports_systemd or gw.is_macos() or gw.is_windows()):
+    supports_rc = gw.supports_freebsd_rc()
+    if not (supports_systemd or supports_rc or gw.is_macos() or gw.is_windows()):
         gw.print_info("No supported service manager found. Run: hermes gateway run")
         return False
     try:
@@ -75,6 +76,8 @@
                 return False
             if supports_systemd:
                 gw.systemd_install(force=False, non_interactive=True)
+            elif supports_rc:
+                gw.freebsd_rc_install(force=False, non_interactive=True)
             elif gw.is_macos():
                 gw.launchd_install(force=False)
             else:
@@ -86,6 +89,8 @@
             record_service_choice("install", config)
         if supports_systemd:
             gw.systemd_start()
+        elif supports_rc:
+            gw.freebsd_rc_start()
         elif gw.is_macos():
             gw.launchd_start()
         else:
