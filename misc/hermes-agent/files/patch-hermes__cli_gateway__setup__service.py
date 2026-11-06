--- hermes_cli/gateway_setup_service.py.orig	2026-11-06 16:56:46 UTC
+++ hermes_cli/gateway_setup_service.py
@@ -55,7 +55,8 @@ def ensure_gateway_service(context: str = "setup", *, 
         gw.print_info("Run hermes gateway run as the container main process; use a Docker restart policy for persistence.")
         return False
     supports_systemd = gw.supports_systemd_services()
-    if not (supports_systemd or gw.is_macos() or gw.is_windows()):
+    supports_rc = gw.supports_freebsd_rc()
+    if not (supports_systemd or supports_rc or gw.is_macos() or gw.is_windows()):
         gw.print_info("No supported service manager found. Run: hermes gateway run")
         return False
     try:
@@ -75,6 +76,8 @@ def ensure_gateway_service(context: str = "setup", *, 
                 return False
             if supports_systemd:
                 gw.systemd_install(force=False, non_interactive=True)
+            elif supports_rc:
+                gw.freebsd_rc_install(force=False, non_interactive=True)
             elif gw.is_macos():
                 gw.launchd_install(force=False)
             else:
@@ -86,6 +89,8 @@ def ensure_gateway_service(context: str = "setup", *, 
             record_service_choice("install", config)
         if supports_systemd:
             gw.systemd_start()
+        elif supports_rc:
+            gw.freebsd_rc_start()
         elif gw.is_macos():
             gw.launchd_start()
         else:
