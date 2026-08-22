--- hermes_cli/gateway.py.orig	2026-08-20 21:23:13 UTC
+++ hermes_cli/gateway.py
@@ -1945,6 +1945,45 @@ def supports_systemd_services() -> bool:
     return True
 
 
+FREEBSD_RC_SCRIPT_NAME = "hermes_gateway"
+FREEBSD_RC_SCRIPT_PATH = Path("/usr/local/etc/rc.d") / FREEBSD_RC_SCRIPT_NAME
+FREEBSD_RC_VAR = "hermes_gateway_enable"
+
+
+def is_freebsd() -> bool:
+    return sys.platform.startswith("freebsd")
+
+
+# Privilege escalators, in preference order.  sudo(8) is preferred so behavior
+# matches the Linux path used elsewhere in the codebase; doas(1) is the
+# common lightweight alternative on FreeBSD.
+_FREEBSD_PRIV_ESCALATORS = ("sudo", "doas")
+
+
+def _freebsd_privilege_escalator() -> str | None:
+    """Return the first available escalator command name, or None."""
+    for name in _FREEBSD_PRIV_ESCALATORS:
+        if shutil.which(name) is not None:
+            return name
+    return None
+
+
+def supports_freebsd_rc() -> bool:
+    """Return True only when running on FreeBSD, the port-installed rc.d
+    script exists, AND the caller has a viable path to root (already root, or
+    a privilege escalator like sudo/doas is on PATH).  Without one, callers
+    cannot drive service(8) or sysrc(8), so the dispatcher falls through to
+    the generic "not supported" branch and the user can still run
+    `hermes gateway run` in the foreground."""
+    if not is_freebsd():
+        return False
+    if shutil.which("service") is None:
+        return False
+    if not FREEBSD_RC_SCRIPT_PATH.exists():
+        return False
+    return _freebsd_is_root() or _freebsd_privilege_escalator() is not None
+
+
 def is_macos() -> bool:
     return sys.platform == "darwin"
 
@@ -2829,7 +2868,8 @@ def ensure_gateway_service(context: str = "setup") -> 
         return False
 
     supports_systemd = supports_systemd_services()
-    if not (supports_systemd or is_macos() or is_windows()):
+    supports_rc = supports_freebsd_rc()
+    if not (supports_systemd or supports_rc or is_macos() or is_windows()):
         print_info("  No supported service manager found on this host.")
         print_info("  Run the gateway in the foreground with: hermes gateway")
         return False
@@ -2847,6 +2887,8 @@ def ensure_gateway_service(context: str = "setup") -> 
             print_info("  Installing the gateway background service ...")
             if supports_systemd:
                 systemd_install(force=False, non_interactive=True)
+            elif supports_rc:
+                freebsd_rc_install(force=False, non_interactive=True)
             elif is_macos():
                 launchd_install(force=False)
             else:
@@ -2859,6 +2901,8 @@ def ensure_gateway_service(context: str = "setup") -> 
 
         if supports_systemd:
             systemd_start()
+        elif supports_rc:
+            freebsd_rc_start()
         elif is_macos():
             launchd_start()
         else:
@@ -5287,6 +5331,129 @@ def launchd_status(deep: bool = False):
 
 
 # =============================================================================
+# FreeBSD rc.d service (port-installed hermes_gateway script)
+# =============================================================================
+#
+# The rc.d script itself is shipped by misc/hermes-agent; the CLI only flips
+# rcvar via sysrc(8) and drives lifecycle via service(8).  ``system=`` is
+# accepted for API parity with systemd_* helpers but is a no-op — rc.d is
+# inherently system-scoped.
+
+
+def _freebsd_is_root() -> bool:
+    try:
+        return os.geteuid() == 0
+    except AttributeError:
+        return False
+
+
+def _freebsd_run_or_print(cmd: list[str], *, action: str) -> bool:
+    """Run *cmd* directly when root; otherwise prepend the first available
+    privilege escalator (sudo, then doas).  When none is available, print the
+    command for the user to run manually and return False.  Returns True on
+    success."""
+    if _freebsd_is_root():
+        try:
+            subprocess.run(cmd, check=True)
+            return True
+        except subprocess.CalledProcessError as e:
+            print(f"✗ Failed to {action} {FREEBSD_RC_SCRIPT_NAME}: exit {e.returncode}")
+            return False
+
+    escalator = _freebsd_privilege_escalator()
+    if escalator is None:
+        print(f"  Run as root: {' '.join(cmd)}")
+        return False
+
+    try:
+        subprocess.run([escalator] + cmd, check=True)
+        return True
+    except subprocess.CalledProcessError as e:
+        print(f"✗ Failed to {action} {FREEBSD_RC_SCRIPT_NAME}: exit {e.returncode}")
+        return False
+
+
+def freebsd_rc_install(
+    force: bool = False,
+    system: bool = False,
+    run_as_user: str | None = None,
+    enable_on_startup: bool = True,
+    non_interactive: bool = False,
+):
+    """Enable hermes_gateway in /etc/rc.conf.  Does NOT start — dispatcher
+    starts via freebsd_rc_start when the user opts in."""
+    del force, system, enable_on_startup, non_interactive  # dispatcher parity
+
+    import getpass
+    target_user = run_as_user or getpass.getuser()
+
+    print(f"Enabling {FREEBSD_RC_VAR}=YES in /etc/rc.conf...")
+    _freebsd_run_or_print(
+        ["sysrc", f"{FREEBSD_RC_VAR}=YES", f"hermes_gateway_user={target_user}"],
+        action="enable",
+    )
+
+
+def freebsd_rc_uninstall(system: bool = False):
+    """Stop the gateway and remove its rcvar.  Leaves the rc.d script in place
+    (owned by pkg)."""
+    del system
+    print(f"Stopping {FREEBSD_RC_SCRIPT_NAME}...")
+    _freebsd_run_or_print(
+        ["service", FREEBSD_RC_SCRIPT_NAME, "stop"],
+        action="stop",
+    )
+    print(f"Removing {FREEBSD_RC_VAR} from /etc/rc.conf...")
+    _freebsd_run_or_print(
+        ["sysrc", "-x", FREEBSD_RC_VAR],
+        action="disable",
+    )
+    print(f"  (The rc.d script {FREEBSD_RC_SCRIPT_PATH} is owned by the package")
+    print("   manager — use 'pkg delete hermes-agent' to remove it.)")
+
+
+def freebsd_rc_start(system: bool = False):
+    del system
+    _freebsd_run_or_print(
+        ["service", FREEBSD_RC_SCRIPT_NAME, "start"],
+        action="start",
+    )
+
+
+def freebsd_rc_stop(system: bool = False):
+    del system
+    _freebsd_run_or_print(
+        ["service", FREEBSD_RC_SCRIPT_NAME, "stop"],
+        action="stop",
+    )
+
+
+def freebsd_rc_restart(system: bool = False):
+    del system
+    _freebsd_run_or_print(
+        ["service", FREEBSD_RC_SCRIPT_NAME, "restart"],
+        action="restart",
+    )
+
+
+def freebsd_rc_status(deep: bool = False, system: bool = False, full: bool = False):
+    del deep, system, full
+    result = subprocess.run(
+        ["service", FREEBSD_RC_SCRIPT_NAME, "status"],
+        check=False,
+    )
+    if result.returncode != 0:
+        print()
+        print("To start the gateway:")
+        if _freebsd_is_root():
+            print("  hermes gateway start")
+        else:
+            escalator = _freebsd_privilege_escalator() or "sudo"
+            print(f"  {escalator} service {FREEBSD_RC_SCRIPT_NAME} start")
+            print(f"  {escalator} sysrc {FREEBSD_RC_VAR}=YES   # start at boot")
+
+
+# =============================================================================
 # Gateway Runner
 # =============================================================================
 
@@ -7560,6 +7727,18 @@ def _gateway_command_inner(args):
             )
             if start_now:
                 systemd_start(system=system)
+        elif supports_freebsd_rc():
+            non_interactive = not (hasattr(sys.stdin, "isatty") and sys.stdin.isatty())
+            _sn = getattr(args, "start_now", None)
+            if _sn is not None:
+                start_now = _sn
+            elif not non_interactive:
+                start_now = prompt_yes_no("Start the gateway now after installing the service?", True)
+            else:
+                start_now = True
+            freebsd_rc_install(force=force, run_as_user=run_as_user)
+            if start_now:
+                freebsd_rc_start()
         elif is_macos():
             launchd_install(force)
         elif is_windows():
@@ -7634,6 +7813,8 @@ def _gateway_command_inner(args):
             sys.exit(1)
         if supports_systemd_services():
             systemd_uninstall(system=system)
+        elif supports_freebsd_rc():
+            freebsd_rc_uninstall()
         elif is_macos():
             launchd_uninstall()
         elif is_windows():
@@ -7687,6 +7868,8 @@ def _gateway_command_inner(args):
             sys.exit(1)
         if supports_systemd_services():
             systemd_start(system=system)
+        elif supports_freebsd_rc():
+            freebsd_rc_start()
         elif is_macos():
             launchd_start()
         elif is_windows():
@@ -7764,6 +7947,18 @@ def _gateway_command_inner(args):
                     service_available = True
                 except subprocess.CalledProcessError:
                     pass
+            elif supports_freebsd_rc():
+                try:
+                    freebsd_rc_stop()
+                    service_available = True
+                except subprocess.CalledProcessError:
+                    pass
+            elif supports_freebsd_rc():
+                try:
+                    freebsd_rc_stop()
+                    service_available = True
+                except subprocess.CalledProcessError:
+                    pass
             elif is_macos() and get_launchd_plist_path().exists():
                 try:
                     launchd_stop()
@@ -7861,6 +8056,12 @@ def _gateway_command_inner(args):
                     service_stopped = True
                 except subprocess.CalledProcessError:
                     pass
+            elif supports_freebsd_rc():
+                try:
+                    freebsd_rc_stop()
+                    service_stopped = True
+                except subprocess.CalledProcessError:
+                    pass
             elif is_macos() and get_launchd_plist_path().exists():
                 try:
                     launchd_stop()
@@ -7889,6 +8090,8 @@ def _gateway_command_inner(args):
                 or get_systemd_unit_path(system=True).exists()
             ):
                 systemd_start(system=system)
+            elif supports_freebsd_rc():
+                freebsd_rc_start()
             elif is_macos() and get_launchd_plist_path().exists():
                 launchd_start()
             elif is_windows():
@@ -7915,6 +8118,13 @@ def _gateway_command_inner(args):
                 service_available = True
             except subprocess.CalledProcessError:
                 pass
+        elif supports_freebsd_rc():
+            service_configured = True
+            try:
+                freebsd_rc_restart()
+                service_available = True
+            except subprocess.CalledProcessError:
+                pass
         elif is_macos() and get_launchd_plist_path().exists():
             service_configured = True
             try:
@@ -7997,6 +8207,9 @@ def _gateway_command_inner(args):
             or get_systemd_unit_path(system=True).exists()
         ):
             systemd_status(deep, system=system, full=full)
+            _print_gateway_process_mismatch(snapshot)
+        elif supports_freebsd_rc():
+            freebsd_rc_status(deep, system=system, full=full)
             _print_gateway_process_mismatch(snapshot)
         elif is_macos() and get_launchd_plist_path().exists():
             launchd_status(deep)
