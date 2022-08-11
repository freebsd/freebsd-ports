--- packages/onionprobe/config.py.orig	2022-08-07 13:42:37 UTC
+++ packages/onionprobe/config.py
@@ -476,9 +476,9 @@ def cmdline_parser_compiler(default_source=None):
     # package)
     config_template = os.path.normpath(os.path.join(basepath, 'configs', 'tor.yaml'))
 
-    # Fallback config_template to /etc/onionprobe
+    # Fallback config_template to %%ETCDIR%%
     if not os.path.exists(config_template):
-        config_template = os.path.normpath(os.path.join(os.sep, 'etc', 'onionprobe', 'tor.yaml'))
+        config_template = '%%ETCDIR%%/tor.yaml'
 
     # Try to use the configs/ folder as the default output_folder (will match
     # when running directly from the Onionprobe repository or from the python
