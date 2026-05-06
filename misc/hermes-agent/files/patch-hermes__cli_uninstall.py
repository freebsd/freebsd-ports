--- hermes_cli/uninstall.py.orig	2026-05-06 08:29:55 UTC
+++ hermes_cli/uninstall.py
@@ -201,6 +201,32 @@ def uninstall_gateway_service():
         except Exception as e:
             log_warn(f"Could not remove launchd gateway service: {e}")
 
+    # 4. FreeBSD: stop the rc.d service and remove its rcvar from rc.conf.
+    #    The rc script itself (/usr/local/etc/rc.d/hermes_gateway) is owned
+    #    by the FreeBSD package — `pkg delete hermes-agent` removes it.
+    elif system == "FreeBSD":
+        try:
+            from hermes_cli.gateway import (
+                supports_freebsd_rc,
+                FREEBSD_RC_SCRIPT_NAME,
+                FREEBSD_RC_VAR,
+            )
+            if supports_freebsd_rc():
+                sudo = [] if os.geteuid() == 0 else (["sudo"] if shutil.which("sudo") else None)
+                if sudo is None:
+                    log_warn(f"  Need root to disable {FREEBSD_RC_SCRIPT_NAME}. "
+                             f"Run: sudo service {FREEBSD_RC_SCRIPT_NAME} stop && "
+                             f"sudo sysrc -x {FREEBSD_RC_VAR}")
+                else:
+                    subprocess.run(sudo + ["service", FREEBSD_RC_SCRIPT_NAME, "stop"],
+                                   capture_output=True, check=False)
+                    subprocess.run(sudo + ["sysrc", "-x", FREEBSD_RC_VAR],
+                                   capture_output=True, check=False)
+                    log_success(f"Stopped and disabled {FREEBSD_RC_SCRIPT_NAME}")
+                    stopped_something = True
+        except Exception as e:
+            log_warn(f"Could not disable FreeBSD gateway service: {e}")
+
     return stopped_something
 
 
