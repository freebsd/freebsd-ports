--- hermes_cli/gateway.py.orig	2026-11-06 16:56:46 UTC
+++ hermes_cli/gateway.py
@@ -3914,6 +3914,29 @@ def systemd_status(deep: bool = False, system: bool = 
 
 
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
 
@@ -4799,6 +4822,8 @@ def _service_backend(*, windows: bool = True) -> str |
     predicate order every subcommand routes on. ``windows=False`` never probes ``is_windows()``."""
     if supports_systemd_services():
         return "systemd"
+    if supports_freebsd_rc():
+        return "freebsd_rc"
     if is_macos():
         return "launchd"
     if windows and is_windows():
@@ -4812,6 +4837,8 @@ def _service_call(backend: str, verb: str, system: boo
     Each systemd/launchd verb refuses a definition pinning another HERMES_HOME itself."""
     if backend == "windows":
         return getattr(_gw_windows(), verb)()
+    if backend == "freebsd_rc":
+        return globals()[f"freebsd_rc_{verb}"]()
     if backend == "launchd":
         return globals()[f"launchd_{verb}"]()
     fn = globals()[f"systemd_{verb}"]
@@ -4989,6 +5016,8 @@ def _installed_service_kind_for(windows) -> str | None
     (a thunk so it runs last, like every caller's original ladder), else None."""
     if _systemd_unit_installed():
         return "systemd"
+    if supports_freebsd_rc():
+        return "freebsd_rc"
     if is_macos() and get_launchd_plist_path().exists():
         return "launchd"
     return "windows" if windows() else None
