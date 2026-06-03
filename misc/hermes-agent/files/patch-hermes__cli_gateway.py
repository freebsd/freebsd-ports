--- hermes_cli/gateway.py.orig	2026-05-16 09:59:15 UTC
+++ hermes_cli/gateway.py	2026-05-19 11:14:21.477531000 +0200
@@ -1245,9 +1245,177 @@
     try:
         return not bool(sys.stdin and sys.stdin.isatty())
     except (ValueError, OSError):
+        return True
+
+
+def is_freebsd() -> bool:
+    return sys.platform.startswith('freebsd')
+
+
+# =============================================================================
+# FreeBSD rc.d service helpers
+# =============================================================================
+#
+# On FreeBSD the rc.d scripts (hermes_gateway, hermes_dashboard) are shipped by
+# the FreeBSD port at /usr/local/etc/rc.d/.  Hermes does NOT generate or write
+# them at runtime — there is no per-user scope on FreeBSD, only the system one,
+# and editing rc.d / rc.conf requires root.  These helpers therefore:
+#   * detect whether the rc script is present (port installed)
+#   * shell out to service(8) for start/stop/restart/status
+#   * shell out to sysrc(8) to flip hermes_gateway_enable=YES / -x in rc.conf
+#   * print exact sudo commands when running as a non-root user
+# This mirrors the systemd_*/launchd_* command shape so the dispatcher in
+# gateway_command() can branch on platform without duplicating logic.
+
+FREEBSD_RC_SCRIPT_NAME = "hermes_gateway"
+FREEBSD_RC_SCRIPT_PATH = Path("/usr/local/etc/rc.d") / FREEBSD_RC_SCRIPT_NAME
+FREEBSD_RC_VAR = "hermes_gateway_enable"
+
+
+def supports_freebsd_rc() -> bool:
+    """Return True when running on FreeBSD with the hermes_gateway rc.d script
+    installed by the port.  We do NOT try to install the rc script ourselves —
+    that's the package manager's job."""
+    if not is_freebsd():
+        return False
+    if shutil.which("service") is None:
+        return False
+    return FREEBSD_RC_SCRIPT_PATH.exists()
+
+
+def _freebsd_is_root() -> bool:
+    try:
+        return os.geteuid() == 0
+    except AttributeError:
+        return False
+
+
+def _freebsd_sudo_prefix() -> list[str]:
+    """Return [] if already root, ['sudo'] otherwise."""
+    return [] if _freebsd_is_root() else ["sudo"]
+
+
+def _freebsd_run_or_print(cmd: list[str], *, action: str) -> bool:
+    """Run *cmd* (prepending sudo when needed). If sudo is required and
+    unavailable in batch mode, print the exact command for the user to run.
+    Returns True on success, False otherwise.  *action* is a short verb used
+    for log messages (e.g. 'start', 'enable')."""
+    if _freebsd_is_root():
+        try:
+            subprocess.run(cmd, check=True)
+            return True
+        except subprocess.CalledProcessError as e:
+            print(f"✗ Failed to {action} hermes_gateway: exit {e.returncode}")
+            return False
+
+    if shutil.which("sudo") is None:
+        print(f"  Run as root: {' '.join(cmd)}")
+        return False
+
+    sudo_cmd = ["sudo"] + cmd
+    try:
+        subprocess.run(sudo_cmd, check=True)
         return True
+    except subprocess.CalledProcessError as e:
+        print(f"✗ Failed to {action} hermes_gateway: exit {e.returncode}")
+        return False
+
+
+def freebsd_rc_install(force: bool = False, system: bool = False, run_as_user: str | None = None):
+    """Enable hermes_gateway in /etc/rc.conf and start it.
+
+    The rc.d script itself is provided by the FreeBSD port; this function only
+    flips the rcvar and (re)starts the service.  --system is accepted for
+    parity with the systemd dispatcher but is a no-op on FreeBSD (rc.d only
+    has system scope).  --run-as-user is also a no-op: the rc script reads
+    hermes_gateway_user from rc.conf, set it there with sysrc.
+    """
+    del force, system  # noqa: F841 — accepted for dispatcher parity
+
+    if not FREEBSD_RC_SCRIPT_PATH.exists():
+        print(f"✗ {FREEBSD_RC_SCRIPT_PATH} not found.")
+        print("  The hermes_gateway rc.d script is shipped by the FreeBSD port.")
+        print("  Install with: sudo pkg install hermes-agent")
+        sys.exit(1)
+
+    import getpass
+    target_user = run_as_user or getpass.getuser()
+
+    print(f"Enabling {FREEBSD_RC_VAR}=YES in /etc/rc.conf...")
+    if not _freebsd_run_or_print(
+        ["sysrc", f"{FREEBSD_RC_VAR}=YES", f"hermes_gateway_user={target_user}"],
+        action="enable",
+    ):
+        return
+    print(f"Starting {FREEBSD_RC_SCRIPT_NAME}...")
+    _freebsd_run_or_print(
+        ["service", FREEBSD_RC_SCRIPT_NAME, "start"],
+        action="start",
+    )
 
 
+def freebsd_rc_uninstall(system: bool = False):
+    """Stop hermes_gateway and remove its rcvar from /etc/rc.conf.  Does NOT
+    delete the rc.d script itself — that belongs to the FreeBSD package."""
+    del system  # noqa: F841
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
+    # `service X status` doesn't need root; run directly without sudo.
+    try:
+        result = subprocess.run(
+            ["service", FREEBSD_RC_SCRIPT_NAME, "status"],
+            check=False,
+        )
+        if result.returncode != 0:
+            print()
+            print("To start the gateway:")
+            if _freebsd_is_root():
+                print("  hermes gateway start")
+            else:
+                print(f"  sudo service {FREEBSD_RC_SCRIPT_NAME} start")
+                print(f"  sudo sysrc {FREEBSD_RC_VAR}=YES   # start at boot")
+    except FileNotFoundError:
+        print("✗ service(8) not found — is this really FreeBSD?")
+
+
 # =============================================================================
 # Service Configuration
 # =============================================================================
@@ -5057,6 +5225,8 @@
                 print_info("  Or use tmux/screen for persistence: tmux new -s hermes 'hermes gateway run'")
                 print()
             systemd_install(force=force, system=system, run_as_user=run_as_user)
+        elif supports_freebsd_rc():
+            freebsd_rc_install(force=force, system=system, run_as_user=run_as_user)
         elif is_macos():
             launchd_install(force)
         elif is_windows():
@@ -5096,6 +5266,8 @@
             sys.exit(1)
         if supports_systemd_services():
             systemd_uninstall(system=system)
+        elif supports_freebsd_rc():
+            freebsd_rc_uninstall(system=system)
         elif is_macos():
             launchd_uninstall()
         elif is_windows():
@@ -5129,6 +5301,8 @@
             sys.exit(1)
         if supports_systemd_services():
             systemd_start(system=system)
+        elif supports_freebsd_rc():
+            freebsd_rc_start(system=system)
         elif is_macos():
             launchd_start()
         elif is_windows():
@@ -5167,9 +5341,21 @@
             if supports_systemd_services() and (get_systemd_unit_path(system=False).exists() or get_systemd_unit_path(system=True).exists()):
                 try:
                     systemd_stop(system=system)
+                    service_available = True
+                except subprocess.CalledProcessError:
+                    pass
+            elif supports_freebsd_rc():
+                try:
+                    freebsd_rc_stop(system=system)
                     service_available = True
                 except subprocess.CalledProcessError:
                     pass
+            elif supports_freebsd_rc():
+                try:
+                    freebsd_rc_stop(system=system)
+                    service_available = True
+                except subprocess.CalledProcessError:
+                    pass
             elif is_macos() and get_launchd_plist_path().exists():
                 try:
                     launchd_stop()
@@ -5236,6 +5422,12 @@
             if supports_systemd_services() and (get_systemd_unit_path(system=False).exists() or get_systemd_unit_path(system=True).exists()):
                 try:
                     systemd_stop(system=system)
+                    service_stopped = True
+                except subprocess.CalledProcessError:
+                    pass
+            elif supports_freebsd_rc():
+                try:
+                    freebsd_rc_stop(system=system)
                     service_stopped = True
                 except subprocess.CalledProcessError:
                     pass
@@ -5263,6 +5455,8 @@
             print("Starting gateway...")
             if supports_systemd_services() and (get_systemd_unit_path(system=False).exists() or get_systemd_unit_path(system=True).exists()):
                 systemd_start(system=system)
+            elif supports_freebsd_rc():
+                freebsd_rc_start(system=system)
             elif is_macos() and get_launchd_plist_path().exists():
                 launchd_start()
             elif is_windows():
@@ -5282,6 +5476,13 @@
                 service_available = True
             except subprocess.CalledProcessError:
                 pass
+        elif supports_freebsd_rc():
+            service_configured = True
+            try:
+                freebsd_rc_restart(system=system)
+                service_available = True
+            except subprocess.CalledProcessError:
+                pass
         elif is_macos() and get_launchd_plist_path().exists():
             service_configured = True
             try:
@@ -5347,6 +5548,9 @@
         if supports_systemd_services() and (get_systemd_unit_path(system=False).exists() or get_systemd_unit_path(system=True).exists()):
             systemd_status(deep, system=system, full=full)
             _print_gateway_process_mismatch(snapshot)
+        elif supports_freebsd_rc():
+            freebsd_rc_status(deep=deep, system=system, full=full)
+            _print_gateway_process_mismatch(snapshot)
         elif is_macos() and get_launchd_plist_path().exists():
             launchd_status(deep)
             _print_gateway_process_mismatch(snapshot)
