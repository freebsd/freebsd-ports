--- hermes_cli/gateway_runtime_service.py.orig	2026-10-26 21:50:19 UTC
+++ hermes_cli/gateway_runtime_service.py
@@ -261,8 +261,10 @@ def discover_existing_gateway_service(home: Path, *, d
 def discover_existing_gateway_service(home: Path, *, deadline: float) -> ExistingService | None:
     from hermes_cli.service_manager import _s6_running
 
+    # FreeBSD: sys.platform carries the major version; no supervisor probe, unmanaged start.
+    platform = "freebsd" if sys.platform.startswith("freebsd") else sys.platform
     backend = _s6 if _s6_running() else {"linux": _systemd, "darwin": _launchd, "win32": _windows,
-                                         "android": _no_supervisor}.get(sys.platform)
+                                         "android": _no_supervisor, "freebsd": _no_supervisor}.get(platform)
     if backend is None:
         raise RuntimeStartError("unsupported_supervisor_platform")
     try:
