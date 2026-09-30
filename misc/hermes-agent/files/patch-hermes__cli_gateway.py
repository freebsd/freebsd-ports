--- hermes_cli/gateway.py.orig	2026-09-24 10:08:47 UTC
+++ hermes_cli/gateway.py
@@ -2710,7 +2710,8 @@ def ensure_gateway_service(context: str = "setup") -> 
         return False
 
     supports_systemd = supports_systemd_services()
-    if not (supports_systemd or is_macos() or is_windows()):
+    supports_rc = supports_freebsd_rc()
+    if not (supports_systemd or supports_rc or is_macos() or is_windows()):
         print_info("  No supported service manager found on this host.")
         print_info("  Run the gateway in the foreground with: hermes gateway")
         return False
@@ -2728,6 +2729,8 @@ def ensure_gateway_service(context: str = "setup") -> 
             print_info("  Installing the gateway background service ...")
             if supports_systemd:
                 systemd_install(force=False, non_interactive=True)
+            elif supports_rc:
+                freebsd_rc_install(force=False, non_interactive=True)
             elif is_macos():
                 launchd_install(force=False)
             else:
@@ -2736,6 +2739,8 @@ def ensure_gateway_service(context: str = "setup") -> 
                 return True
         if supports_systemd:
             systemd_start()
+        elif supports_rc:
+            freebsd_rc_start()
         elif is_macos():
             launchd_start()
         else:
@@ -3459,6 +3464,29 @@ def systemd_status(deep: bool = False, system: bool = 
 
 
 # =============================================================================
+# FreeBSD rc.d service (port-installed hermes_gateway script)
+# =============================================================================
+
+
+from hermes_cli.gateway_freebsd import (  # noqa: E402,F401 — facade re-exports; tests patch here
+    FREEBSD_RC_SCRIPT_NAME,
+    FREEBSD_RC_SCRIPT_PATH,
+    FREEBSD_RC_VAR,
+    is_freebsd,
+    _freebsd_is_root,
+    _freebsd_privilege_escalator,
+    supports_freebsd_rc,
+    _freebsd_run_or_print,
+    freebsd_rc_install,
+    freebsd_rc_uninstall,
+    freebsd_rc_start,
+    freebsd_rc_stop,
+    freebsd_rc_restart,
+    freebsd_rc_status,
+)
+
+
+# =============================================================================
 # Launchd (macOS)
 # =============================================================================
 
@@ -4317,6 +4345,8 @@ def _service_backend(*, windows: bool = True) -> str |
     predicate order every subcommand routes on. ``windows=False`` never probes ``is_windows()``."""
     if supports_systemd_services():
         return "systemd"
+    if supports_freebsd_rc():
+        return "freebsd_rc"
     if is_macos():
         return "launchd"
     if windows and is_windows():
@@ -4329,6 +4359,8 @@ def _service_call(backend: str, verb: str, system: boo
     can monkeypatch them; only systemd takes a scope, and ``system=None`` omits it (wizard restart)."""
     if backend == "windows":
         return getattr(_gw_windows(), verb)()
+    if backend == "freebsd_rc":
+        return globals()[f"freebsd_rc_{verb}"]()
     if backend == "launchd":
         return globals()[f"launchd_{verb}"]()
     fn = globals()[f"systemd_{verb}"]
@@ -4506,6 +4538,8 @@ def _installed_service_kind_for(windows) -> str | None
     (a thunk so it runs last, like every caller's original ladder), else None."""
     if _systemd_unit_installed():
         return "systemd"
+    if supports_freebsd_rc():
+        return "freebsd_rc"
     if is_macos() and get_launchd_plist_path().exists():
         return "launchd"
     return "windows" if windows() else None
