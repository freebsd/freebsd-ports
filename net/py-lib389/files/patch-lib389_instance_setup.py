--- lib389/instance/setup.py.orig	2026-06-29 17:03:20 UTC
+++ lib389/instance/setup.py
@@ -826,10 +826,10 @@ class SetupDs(object):
         # which subsequently breaks containers starting as instance.start then believes
         # it COULD check the ds status. The times we need to check for systemd are mainly
         # in other environments that use systemd natively in their containers.
-        container_result = 1
-        if not self.containerised:
+        container_result = None
+        if not self.containerised and shutil.which("systemd-detect-virt"):
             container_result = subprocess.run(["systemd-detect-virt", "-c"], stdout=subprocess.PIPE)
-        if self.containerised or container_result.returncode == 0:
+        if self.containerised or (container_result is not None and container_result.returncode == 0):
             # In a container, set the db_home_dir to the db path
             self.log.debug("Container detected setting db home directory to db directory.")
             slapd['db_home_dir'] = slapd['db_dir']
