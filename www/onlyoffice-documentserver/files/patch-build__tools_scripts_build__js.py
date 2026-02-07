--- build_tools/scripts/build_js.py.orig	2021-12-21 17:52:55 UTC
+++ build_tools/scripts/build_js.py
@@ -97,7 +97,7 @@ def _run_npm_cli(directory):
   return base.cmd_in_dir(directory, "npm", ["install", "-g", "grunt-cli"])
 
 def _run_grunt(directory, params=[]):
-  return base.cmd_in_dir(directory, "grunt", params)
+  return base.cmd_in_dir(directory, "%%WRKSRC%%/sdkjs/node_modules/.bin/grunt", params)
 
 def build_interface(directory):
   _run_npm(directory)
