"""Gateway FreeBSD rc.d backend: rcvar management via sysrc(8), lifecycle via service(8).

The rc.d script itself is shipped by the misc/hermes-agent port; the CLI only flips rcvar
and drives lifecycle. ``system=`` is accepted for API parity with the ``systemd_*`` helpers
but is a no-op — rc.d is inherently system-scoped.

Extracted-backend conventions match ``hermes_cli/gateway_launchd.py``: bodies read facade
helpers through ``_gw()`` (late binding on ``hermes_cli.gateway``) so the seams tests and
callers patch on the facade keep intercepting the moved code.
"""
from __future__ import annotations

from pathlib import Path
import os
import shutil
import subprocess
import sys


def _gw():
    from hermes_cli import gateway  # late: the facade imports this module
    return gateway


FREEBSD_RC_SCRIPT_NAME = "hermes_gateway"
FREEBSD_RC_SCRIPT_PATH = Path("/usr/local/etc/rc.d") / FREEBSD_RC_SCRIPT_NAME
FREEBSD_RC_VAR = "hermes_gateway_enable"

# Privilege escalators, in preference order. sudo(8) is preferred so behavior matches the
# Linux path used elsewhere; doas(1) is the common lightweight FreeBSD alternative.
_FREEBSD_PRIV_ESCALATORS = ("sudo", "doas")


def is_freebsd() -> bool:
    return sys.platform.startswith("freebsd")


def _freebsd_is_root() -> bool:
    try:
        return os.geteuid() == 0
    except AttributeError:
        return False


def _freebsd_privilege_escalator() -> str | None:
    """Return the first available escalator command name, or None."""
    for name in _FREEBSD_PRIV_ESCALATORS:
        if shutil.which(name) is not None:
            return name
    return None


def supports_freebsd_rc() -> bool:
    """True only on FreeBSD, with the port-installed rc.d script present AND a viable path
    to root (already root, or sudo/doas on PATH). Without one, callers cannot drive
    service(8) or sysrc(8), so the dispatcher falls through to the generic "not supported"
    branch and the user can still run `hermes gateway run` in the foreground."""
    if not is_freebsd():
        return False
    if shutil.which("service") is None:
        return False
    if not FREEBSD_RC_SCRIPT_PATH.exists():
        return False
    return _freebsd_is_root() or _freebsd_privilege_escalator() is not None


def _freebsd_run_or_print(cmd: list[str], *, action: str) -> bool:
    """Run *cmd* directly when root; otherwise prepend the first available privilege
    escalator. When none is available, print the command for the user to run manually and
    return False. Returns True on success."""
    if _freebsd_is_root():
        try:
            subprocess.run(cmd, check=True)
            return True
        except subprocess.CalledProcessError as e:
            print(f"✗ Failed to {action} {FREEBSD_RC_SCRIPT_NAME}: exit {e.returncode}")
            return False

    escalator = _freebsd_privilege_escalator()
    if escalator is None:
        print(f"  Run as root: {' '.join(cmd)}")
        return False

    try:
        subprocess.run([escalator] + cmd, check=True)
        return True
    except subprocess.CalledProcessError as e:
        print(f"✗ Failed to {action} {FREEBSD_RC_SCRIPT_NAME}: exit {e.returncode}")
        return False


def freebsd_rc_install(
    force: bool = False,
    system: bool = False,
    run_as_user: str | None = None,
    enable_on_startup: bool = True,
    non_interactive: bool = False,
):
    """Enable hermes_gateway in /etc/rc.conf. Does NOT start — the dispatcher starts via
    freebsd_rc_start when the user opts in."""
    del force, system, enable_on_startup, non_interactive  # dispatcher parity

    import getpass
    target_user = run_as_user or getpass.getuser()

    print(f"Enabling {FREEBSD_RC_VAR}=YES in /etc/rc.conf...")
    _freebsd_run_or_print(
        ["sysrc", f"{FREEBSD_RC_VAR}=YES", f"hermes_gateway_user={target_user}"],
        action="enable",
    )


def freebsd_rc_uninstall(system: bool = False):
    """Stop the gateway and remove its rcvar. Leaves the rc.d script in place (pkg-owned)."""
    del system
    print(f"Stopping {FREEBSD_RC_SCRIPT_NAME}...")
    _freebsd_run_or_print(["service", FREEBSD_RC_SCRIPT_NAME, "stop"], action="stop")
    print(f"Removing {FREEBSD_RC_VAR} from /etc/rc.conf...")
    _freebsd_run_or_print(["sysrc", "-x", FREEBSD_RC_VAR], action="disable")
    print(f"  (The rc.d script {FREEBSD_RC_SCRIPT_PATH} is owned by the package")
    print("   manager — use 'pkg delete hermes-agent' to remove it.)")


def freebsd_rc_start(system: bool = False):
    del system
    _freebsd_run_or_print(["service", FREEBSD_RC_SCRIPT_NAME, "start"], action="start")


def freebsd_rc_stop(system: bool = False):
    del system
    _freebsd_run_or_print(["service", FREEBSD_RC_SCRIPT_NAME, "stop"], action="stop")


def freebsd_rc_restart(system: bool = False):
    del system
    _freebsd_run_or_print(["service", FREEBSD_RC_SCRIPT_NAME, "restart"], action="restart")


def freebsd_rc_status(deep: bool = False, system: bool = False, full: bool = False):
    del deep, system, full
    result = subprocess.run(["service", FREEBSD_RC_SCRIPT_NAME, "status"], check=False)
    if result.returncode != 0:
        print()
        print("To start the gateway:")
        if _freebsd_is_root():
            print("  hermes gateway start")
        else:
            escalator = _freebsd_privilege_escalator() or "sudo"
            print(f"  {escalator} service {FREEBSD_RC_SCRIPT_NAME} start")
            print(f"  {escalator} sysrc {FREEBSD_RC_VAR}=YES   # start at boot")
