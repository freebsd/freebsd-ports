--- build_tools/scripts/deploy_server.py.orig	2025-10-15 14:25:47 UTC
+++ build_tools/scripts/deploy_server.py
@@ -102,7 +102,7 @@
     base.generate_doctrenderer_config(converter_dir + "/DoctRenderer.config", "../../../", "server", "", "../../../dictionaries")
 
     # icu
-    base.deploy_icu(core_dir, converter_dir, platform)
+#    base.deploy_icu(core_dir, converter_dir, platform)
 
     base.copy_v8_files(core_dir, converter_dir, platform)
 
@@ -136,9 +136,13 @@
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
