--- hermes_cli/uninstall.py.orig	2026-08-31 19:29:27 UTC
+++ hermes_cli/uninstall.py
@@ -278,7 +278,22 @@ def uninstall_gateway_service():
         except Exception as e:
             log_warn(f"Could not remove launchd gateway service: {e}")
 
-    # 4. Windows: uninstall Scheduled Task + Startup-folder entry.  The
+    # 4. FreeBSD: rcvar disable via freebsd_rc_uninstall (delegates to
+    #    sysrc/service).  The rc.d script itself is pkg-owned and is removed
+    #    by `pkg delete hermes-agent`, not here.
+    elif system == "FreeBSD":
+        try:
+            from hermes_cli.gateway import (
+                supports_freebsd_rc,
+                freebsd_rc_uninstall,
+            )
+            if supports_freebsd_rc():
+                freebsd_rc_uninstall()
+                stopped_something = True
+        except Exception as e:
+            log_warn(f"Could not remove FreeBSD gateway service: {e}")
+
+    # 5. Windows: uninstall Scheduled Task + Startup-folder entry.  The
     #    gateway_windows module already knows how to locate and remove both
     #    code paths (schtasks /Delete + .cmd unlink) and how to stop any
     #    running detached pythonw gateway process.  We call into it so the
