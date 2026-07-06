--- lib389/__init__.py.orig	2026-06-29 17:03:20 UTC
+++ lib389/__init__.py
@@ -1158,6 +1158,14 @@ class DirSrv(SimpleLDAPObject, object):
                 raise e from None
         else:
             self.log.debug("systemd status -> False")
+
+            # Runtime directories may be removed during a system reboot.
+            config_stat = os.stat(self.ds_paths.config_dir)
+            for path in (self.ds_paths.run_dir, self.ds_paths.lock_dir):
+                os.makedirs(path, mode=0o770, exist_ok=True)
+                os.chmod(path, 0o770)
+                os.chown(path, config_stat.st_uid, config_stat.st_gid)
+
             # Start the process.
             # Wait for it to terminate
             # This means the server is probably ready to go ....
