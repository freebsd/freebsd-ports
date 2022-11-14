--- build_tools/scripts/base.py.orig	2021-11-16 08:07:24 UTC
+++ build_tools/scripts/base.py
@@ -1144,9 +1144,15 @@ def support_old_versions_plugins(out_dir):
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
@@ -1282,7 +1288,7 @@ def clone_marketplace_plugin(out_dir, is_name_as_guid=
 def clone_marketplace_plugin(out_dir, is_name_as_guid=False):
   old_cur = os.getcwd()
   os.chdir(out_dir)
-  git_update("onlyoffice.github.io", False, True)
+#  git_update("onlyoffice.github.io", False, True)
   os.chdir(old_cur)
 
   dst_dir_name = "marketplace"
