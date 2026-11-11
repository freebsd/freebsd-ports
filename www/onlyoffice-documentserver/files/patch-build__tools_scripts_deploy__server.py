--- build_tools/scripts/deploy_server.py.orig	2026-09-30 13:05:36 UTC
+++ build_tools/scripts/deploy_server.py
@@ -21,7 +21,7 @@
   base_dir = base.get_script_dir() + "/../out"
   git_dir = base.get_script_dir() + "/../.."
   core_dir = git_dir + "/core"
-  plugins_dir = git_dir + "/sdkjs-plugins"
+  plugins_dir = git_dir + "/onlyoffice.github.io/sdkjs-plugins"
   branding = config.branding()
 
   platforms = config.option("platform").split()
@@ -60,13 +60,13 @@
     base.copy_exe(server_dir + "/DocService", build_server_dir + '/DocService', "docservice")
 
     base.create_dir(build_server_dir + '/FileConverter')
-    base.copy_exe(server_dir + "/FileConverter", build_server_dir + '/FileConverter', "converter")
+#    base.copy_exe(server_dir + "/FileConverter", build_server_dir + '/FileConverter', "converter")
 
     base.create_dir(build_server_dir + '/Metrics')
     base.copy_exe(server_dir + "/Metrics", build_server_dir + '/Metrics', "metrics")
     base.copy_dir(server_dir + '/Metrics/config', build_server_dir + '/Metrics/config')
-    base.create_dir(build_server_dir + '/Metrics/node_modules/modern-syslog/build/Release')
-    base.copy_file(server_dir + "/Metrics/node_modules/modern-syslog/build/Release/core.node", build_server_dir + "/Metrics/node_modules/modern-syslog/build/Release/core.node")
+#    base.create_dir(build_server_dir + '/Metrics/node_modules/modern-syslog/build/Release')
+#    base.copy_file(server_dir + "/Metrics/node_modules/modern-syslog/build/Release/core.node", build_server_dir + "/Metrics/node_modules/modern-syslog/build/Release/core.node")
 
     if "server-admin-panel" in base.get_server_addons() and base.is_exist(server_admin_panel_dir):
       # AdminPanel server part
@@ -115,7 +115,7 @@
     base.generate_doctrenderer_config(converter_dir + "/DoctRenderer.config", "../../../", "server", "", "../../../dictionaries")
 
     # icu
-    base.deploy_icu(core_dir, converter_dir, platform)
+#    base.deploy_icu(core_dir, converter_dir, platform)
 
     base.copy_v8_files(core_dir, converter_dir, platform)
 
@@ -151,9 +151,13 @@
     else:
       base.generate_sdkjs_plugin_list(js_dir + "/sdkjs-plugins/plugin-list-default.json")
     base.create_dir(js_dir + "/sdkjs-plugins/v1")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", js_dir + "/sdkjs-plugins/v1/plugins.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", js_dir + "/sdkjs-plugins/v1/plugins-ui.js")
-    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", js_dir + "/sdkjs-plugins/v1/plugins.css")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", js_dir + "/sdkjs-plugins/v1/plugins.js")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", js_dir + "/sdkjs-plugins/v1/plugins-ui.js")
+#    base.download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", js_dir + "/sdkjs-plugins/v1/plugins.css")
+    base.copy_file(plugins_dir + "/v1/plugins.js", js_dir + "/sdkjs-plugins/v1/plugins.js")
+    base.copy_file(plugins_dir + "/v1/plugins-ui.js", js_dir + "/sdkjs-plugins/v1/plugins-ui.js")
+    base.copy_file(plugins_dir + "/v1/plugins.css", js_dir + "/sdkjs-plugins/v1/plugins.css")
+
     base.support_old_versions_plugins(js_dir + "/sdkjs-plugins")
 
     # tools
