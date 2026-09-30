--- hermes_cli/gateway_setup_wizard.py.orig	2026-09-24 10:08:47 UTC
+++ hermes_cli/gateway_setup_wizard.py
@@ -776,7 +776,7 @@ _WIZARD_BANNER = (
 )
 
 
-_WIZARD_BACKEND_LABELS = {"systemd": "systemd", "launchd": "launchd", "windows": "Scheduled Task"}
+_WIZARD_BACKEND_LABELS = {"systemd": "systemd", "freebsd_rc": "rc.d", "launchd": "launchd", "windows": "Scheduled Task"}
 
 
 # Post-setup guidance when no service backend applies, keyed by the fallthrough reason.
