--- LibreNMS/__init__.py.orig	2023-10-04 13:52:17 UTC
+++ LibreNMS/__init__.py
@@ -167,7 +167,7 @@ def get_config_data(base_dir):
         )
         logger.debug("Traceback:", exc_info=True)
 
-    config_cmd = ["/usr/bin/env", "php", "%s/config_to_json.php" % base_dir]
+    config_cmd = "/usr/local/bin/php %s/config_to_json.php" % base_dir
     try:
         exit_code, output = command_runner(config_cmd, timeout=300, stderr=False)
         if exit_code != 0:
