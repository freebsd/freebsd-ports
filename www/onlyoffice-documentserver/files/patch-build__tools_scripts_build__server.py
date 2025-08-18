--- build_tools/scripts/build_server.py.orig	2025-06-11 12:56:35 UTC
+++ build_tools/scripts/build_server.py
@@ -39,8 +39,12 @@
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
@@ -49,14 +53,15 @@
   if ("windows" == base.host_platform()):
     pkg_target += "-win"
 
-  base.cmd_in_dir(server_dir + "/DocService", "pkg", [".", "-t", pkg_target, "--options", "max_old_space_size=4096", "-o", "docservice"])
-  base.cmd_in_dir(server_dir + "/FileConverter", "pkg", [".", "-t", pkg_target, "-o", "converter"])
-  base.cmd_in_dir(server_dir + "/Metrics", "pkg", [".", "-t", pkg_target, "-o", "metrics"])
+  base.cmd_in_dir(server_dir + "/DocService", pkgBin, [".", "-t", pkg_target, "--options", "max_old_space_size=4096", "-o", "docservice"])
+  base.cmd_in_dir(server_dir + "/FileConverter", pkgBin, [".", "-t", pkg_target, "-o", "converter"])
+  base.cmd_in_dir(server_dir + "/Metrics", pkgBin, [".", "-t", pkg_target, "-o", "metrics"])
 
+
   example_dir = base.get_script_dir() + "/../../document-server-integration/web/documentserver-example/nodejs"
   base.delete_dir(example_dir  + "/node_modules")
   base.cmd_in_dir(example_dir, "npm", ["ci"])
-  base.cmd_in_dir(example_dir, "pkg", [".", "-t", pkg_target, "-o", "example"])
+  base.cmd_in_dir(example_dir, pkgBin, [".", "-t", pkg_target, "-o", "example"])
 
 def build_server_with_addons():
   addons = {}
