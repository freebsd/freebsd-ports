--- build_tools/scripts/build_server.py.orig	2026-05-15 19:11:43 UTC
+++ build_tools/scripts/build_server.py
@@ -61,8 +61,12 @@
       base.copy_file(custom_public_key, server_dir + '/Common/sources')
 
   #node22 packaging has issue https://github.com/yao-pkg/pkg/issues/87
-  pkg_target = "node20"
+  pkg_target = "node%%PKGFETCH_NODE_MAJOR_VERSION%%"
 
+  if ("freebsd" == base.host_platform()):
+    pkg_target += "-freebsd"
+    pkgBin = "%%WRKSRC%%/yao-pkg/node_modules/.bin/pkg"
+
   if ("linux" == base.host_platform()):
     pkg_target += "-linux"
     if (-1 != config.option("platform").find("linux_arm64")):
@@ -73,20 +77,20 @@
 
   docservice_pkg_args = [".", "-t", pkg_target]
   docservice_max_old_space_size = config.option("server-docservice-pkg-max-old-space-size")
-  if "" != docservice_max_old_space_size:
-    docservice_pkg_args += ["--options", "max_old_space_size=" + docservice_max_old_space_size]
+  # if "" != docservice_max_old_space_size:
+  docservice_pkg_args += ["--options", "max_old_space_size=6144", "--fallback-to-source"]
   docservice_pkg_args += ["-o", "docservice"]
 
-  base.cmd_in_dir(server_dir + "/DocService", "pkg", docservice_pkg_args)
-  base.cmd_in_dir(server_dir + "/FileConverter", "pkg", [".", "-t", pkg_target, "-o", "converter"])
-  base.cmd_in_dir(server_dir + "/Metrics", "pkg", [".", "-t", pkg_target, "-o", "metrics"])
+  base.cmd_in_dir(server_dir + "/DocService", pkgBin, docservice_pkg_args)
+#  base.cmd_in_dir(server_dir + "/FileConverter", "pkg", [".", "-t", pkg_target, "-o", "converter"])
+  base.cmd_in_dir(server_dir + "/Metrics", pkgBin, [".", "-t", pkg_target, "-o", "metrics", "--fallback-to-source"])
   if "server-admin-panel" in base.get_server_addons() and base.is_exist(server_admin_panel_dir):
     base.cmd_in_dir(server_admin_panel_dir + "/server", "pkg", [".", "-t", pkg_target, "-o", "adminpanel"])
 
   example_dir = base.get_script_dir() + "/../../document-server-integration/web/documentserver-example/nodejs"
-  base.delete_dir(example_dir  + "/node_modules")
+#  base.delete_dir(example_dir  + "/node_modules")
   base.cmd_in_dir(example_dir, "npm", ["ci"])
-  base.cmd_in_dir(example_dir, "pkg", [".", "-t", pkg_target, "-o", "example"])
+  base.cmd_in_dir(example_dir, pkgBin, [".", "-t", pkg_target, "-o", "example", "--fallback-to-source"])
 
 def build_server_with_addons():
   addons = {}
