--- hermes_cli/uninstall.py.orig	2026-10-23 02:24:27 UTC
+++ hermes_cli/uninstall.py
@@ -334,6 +334,16 @@ def _remove_launchd_gateway() -> bool:
     return bool(plists)
 
 
+def _remove_freebsd_gateway() -> bool:
+    """FreeBSD: disable the rcvar via freebsd_rc_uninstall (delegates to sysrc/service).
+    The rc.d script itself is pkg-owned and is removed by `pkg delete hermes-agent`."""
+    from hermes_cli.gateway import supports_freebsd_rc, freebsd_rc_uninstall
+    if not supports_freebsd_rc():
+        return False
+    freebsd_rc_uninstall()
+    return True
+
+
 def _remove_windows_gateway() -> bool:
     """Windows: uninstall Scheduled Task + Startup-folder entry via ``gateway_windows`` (it owns
     schtasks /Delete, the .cmd unlink and stopping the detached pythonw gateway)."""
@@ -357,6 +367,7 @@ _GATEWAY_SERVICE_REMOVERS = {
 _GATEWAY_SERVICE_REMOVERS = {
     "Linux": (_remove_systemd_gateway, "Could not check systemd gateway services"),
     "Darwin": (_remove_launchd_gateway, "Could not remove launchd gateway service"),
+    "FreeBSD": (_remove_freebsd_gateway, "Could not remove FreeBSD gateway service"),
     "Windows": (_remove_windows_gateway, "Could not check Windows gateway service")}
 
 # Windows helpers. install.ps1 leaves four things no rc file covers: User-scope env vars
