--- build_tools/scripts/base.py.orig	2021-11-16 08:07:24 UTC
+++ build_tools/scripts/base.py
@@ -1092,9 +1092,15 @@ def copy_sdkjs_plugins_server(dst_dir, is_name_as_guid
 def support_old_versions_plugins(out_dir):
   if is_file(out_dir + "/pluginBase.js"):
     return
-  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", out_dir + "/plugins.js")
-  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
-  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", out_dir + "/plugins.css")
+#  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.js", out_dir + "/plugins.js")
+#  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
+#  download("https://onlyoffice.github.io/sdkjs-plugins/v1/plugins.css", out_dir + "/plugins.css")
+  git_dir = get_script_dir() + "/../.."
+  plugins_dir = git_dir + "/sdkjs-plugins"
+  copy_file(plugins_dir + "/v1/plugins.js", out_dir + "/plugins.js")
+  copy_file(plugins_dir + "/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
+  copy_file(plugins_dir + "/v1/plugins.css", out_dir + "/plugins.css")
+
   content_plugin_base = ""
   with open(get_path(out_dir + "/plugins.js"), "r") as file:
     content_plugin_base += file.read()
