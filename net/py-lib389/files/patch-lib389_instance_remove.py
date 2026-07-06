--- lib389/instance/remove.py.orig	2026-06-29 17:03:20 UTC
+++ lib389/instance/remove.py
@@ -96,12 +96,12 @@ def remove_ds_instance(dirsrv, force=False):
         _log.debug("Removing %s" % remove_paths[path_k])
         shutil.rmtree(remove_paths[path_k], ignore_errors=True)
 
-    # Remove parent (/var/lib/dirsrv/slapd-INST)
-    shutil.rmtree(remove_paths['db_dir'].replace('db', ''), ignore_errors=True)
+    # Remove the parent instance data directory.
+    shutil.rmtree(os.path.dirname(remove_paths['db_dir']), ignore_errors=True)
 
-    # Remove /run/slapd-isntance
+    # Remove the configured LDAPI socket.
     try:
-        os.remove(f'/run/slapd-{dirsrv.serverid}.socket')
+        os.remove(dirsrv.ds_paths.ldapi)
     except OSError as e:
         _log.debug("Failed to remove socket file: " + str(e))
 
