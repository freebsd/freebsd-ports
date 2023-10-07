--- LibreNMS/__init__.py.orig	2023-09-19 01:59:06 UTC
+++ LibreNMS/__init__.py
@@ -167,7 +167,7 @@ def get_config_data(base_dir):
         )
         logger.debug("Traceback:", exc_info=True)
 
-    config_cmd = ["/usr/bin/env", "php", "%s/config_to_json.php" % base_dir]
+    config_cmd = "/usr/local/bin/php %s/config_to_json.php" % base_dir
     try:
         exit_code, output = command_runner(config_cmd, timeout=300, stderr=False)
         if exit_code != 0:
@@ -194,7 +194,7 @@ def call_script(script, args=()):
     """
     if script.endswith(".php"):
         # save calling the sh process
-        base = ("/usr/bin/env", "php")
+        base = ("/usr/local/bin/php",)
     else:
         base = ()
 
