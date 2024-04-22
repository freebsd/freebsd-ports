--- build_tools/scripts/build_server.py.orig	2024-02-07 10:44:24.000000000 +0100
+++ build_tools/scripts/build_server.py	2024-03-01 10:53:21.550159000 +0100
@@ -38,8 +38,12 @@ def make():
   if(base.is_exist(custom_public_key)):
       base.copy_file(custom_public_key, server_dir + '/Common/sources')
 
-  pkg_target = "node16"
+  pkg_target = "node18"
 
+  if ("freebsd" == base.host_platform()):
+    pkg_target += "-freebsd"
+    pkgBin = "%%WRKSRC%%/yao-pkg/node_modules/.bin/pkg"
+
   if ("linux" == base.host_platform()):
     pkg_target += "-linux"
     if (-1 != config.option("platform").find("linux_arm64")):
@@ -48,14 +52,15 @@ def make():
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
