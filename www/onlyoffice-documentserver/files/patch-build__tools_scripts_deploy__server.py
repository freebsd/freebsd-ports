--- build_tools/scripts/deploy_server.py.orig	2021-11-16 07:07:24 UTC
+++ build_tools/scripts/deploy_server.py
@@ -92,7 +92,7 @@ def make():
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/icudt58.dll", converter_dir + "/icudt58.dll")
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/icuuc58.dll", converter_dir + "/icuuc58.dll")
 
-    if (0 == platform.find("linux")):
+    if (0 == platform.find("linux") and 0 != platform.find('freebsd')):
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/libicudata.so.58", converter_dir + "/libicudata.so.58")
       base.copy_file(core_dir + "/Common/3dParty/icu/" + platform + "/build/libicuuc.so.58", converter_dir + "/libicuuc.so.58")
 
@@ -102,6 +102,8 @@ def make():
 
     if (0 == platform.find("win")):
       base.copy_files(core_dir + "/Common/3dParty/v8/v8/out.gn/" + platform + "/release/icudt*.dat", converter_dir + "/")
+    elif (0 == platform.find("freebsd")):
+      pass
     elif (-1 == config.option("config").find("use_javascript_core")):
       base.copy_file(core_dir + "/Common/3dParty/v8/v8/out.gn/" + platform + "/icudtl.dat", converter_dir + "/icudtl.dat")
 
@@ -119,9 +121,13 @@ def make():
     base.copy_sdkjs_plugins(js_dir + "/sdkjs-plugins", False, True)
     base.copy_sdkjs_plugins_server(js_dir + "/sdkjs-plugins", False, True)
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
