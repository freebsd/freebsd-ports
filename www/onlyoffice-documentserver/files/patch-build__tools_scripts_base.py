--- build_tools/scripts/base.py.orig	2026-05-15 19:11:43 UTC
+++ build_tools/scripts/base.py
@@ -1152,7 +1152,7 @@
   return
 
 def correct_bundle_identifier(bundle_identifier):
-  return re.sub("[^a-zA-Z0-9\.\-]", "-", bundle_identifier)
+  return re.sub(r"[^a-zA-Z0-9\.\-]", "-", bundle_identifier)
 
 def get_sdkjs_addons():
   result = {}
@@ -1590,9 +1590,15 @@
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
+  plugins_dir = git_dir + "/onlyoffice.github.io/sdkjs-plugins"
+  copy_file(plugins_dir + "/v1/plugins.js", out_dir + "/plugins.js")
+  copy_file(plugins_dir + "/v1/plugins-ui.js", out_dir + "/plugins-ui.js")
+  copy_file(plugins_dir + "/v1/plugins.css", out_dir + "/plugins.css")
+
   content_plugin_base = ""
   with open(get_path(out_dir + "/plugins.js"), "r") as file:
     content_plugin_base += file.read()
@@ -1650,7 +1656,7 @@
 def find_mac_sdk_version():
   sdk_dir = run_command("xcode-select -print-path")['stdout']
   sdk_dir = os.path.join(sdk_dir, "Platforms/MacOSX.platform/Developer/SDKs")
-  sdks = [re.findall('^MacOSX(1\d\.\d+)\.sdk$', s) for s in os.listdir(sdk_dir)]
+  sdks = [re.findall(r'^MacOSX(1\d\.\d+)\.sdk$', s) for s in os.listdir(sdk_dir)]
   sdks = [s[0] for s in sdks if s]
   return sdks[0]
 
@@ -1745,7 +1751,7 @@
 def clone_marketplace_plugin(out_dir, is_name_as_guid=False, is_replace_paths=False, is_delete_git_dir=True, git_owner=""):
   old_cur = os.getcwd()
   os.chdir(out_dir)
-  git_update("onlyoffice.github.io", False, True, git_owner)
+#  git_update("onlyoffice.github.io", False, True, git_owner)
   os.chdir(old_cur)
 
   dst_dir_name = "marketplace"
@@ -1851,7 +1857,7 @@
   if (-1 != old_path.find(origin)):
     return
   new_path = old_path
-  new_path = new_path.replace("$ORIGIN", "\$ORIGIN")
+  new_path = new_path.replace("$ORIGIN", r"\$ORIGIN")
   if ("" != new_path):
     new_path += ":"
   new_path += origin
