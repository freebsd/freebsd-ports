--- build_tools/scripts/build_server.py.orig	2021-11-16 08:07:24 UTC
+++ build_tools/scripts/build_server.py
@@ -17,7 +17,7 @@ def make():
     branding_dir = git_dir + '/' + config.option("branding") + '/server'
 
   base.cmd_in_dir(server_dir, "npm", ["install"])
-  base.cmd_in_dir(server_dir, "grunt", ["--no-color", "-v"] + base.server_addons_param())
+  base.cmd_in_dir(server_dir, "%%WRKSRC%%/server/node_modules/.bin/grunt", ["--no-color", "-v"] + base.server_addons_param())
 
     #env variables
   product_version = base.get_env('PRODUCT_VERSION')
@@ -41,29 +41,34 @@ def make():
   if(base.is_exist(custom_public_key)):
       base.copy_file(custom_public_key, server_build_dir + '/Common/sources')
 
-  pkg_target = "node10"
+  pkg_target = "node16"
 
+  if ("freebsd" == base.host_platform()):
+    pkg_target += "-freebsd"
+    pkgBin = "%%WRKSRC%%/server/node_modules/.bin/pkg"
+    pkg_target = "node16"
+
   if ("linux" == base.host_platform()):
     pkg_target += "-linux"
 
   if ("windows" == base.host_platform()):
     pkg_target += "-win"
 
-  base.cmd_in_dir(server_build_dir + "/DocService", "pkg", [".", "-t", pkg_target, "--options", "max_old_space_size=4096", "-o", "docservice"])
-  base.cmd_in_dir(server_build_dir + "/FileConverter", "pkg", [".", "-t", pkg_target, "-o", "converter"])
-  base.cmd_in_dir(server_build_dir + "/Metrics", "pkg", [".", "-t", pkg_target, "-o", "metrics"])
+  base.cmd_in_dir(server_build_dir + "/DocService", pkgBin, [".", "-t", pkg_target, "--options", "max_old_space_size=4096", "-o", "docservice"])
+  base.cmd_in_dir(server_build_dir + "/FileConverter", pkgBin, [".", "-t", pkg_target, "-o", "converter"])
+  base.cmd_in_dir(server_build_dir + "/Metrics", pkgBin, [".", "-t", pkg_target, "-o", "metrics"])
 
   example_dir = base.get_script_dir() + "/../../document-server-integration/web/documentserver-example/nodejs"
   base.delete_dir(example_dir  + "/node_modules")
   base.cmd_in_dir(example_dir, "npm", ["install"])
   sync_rpc_lib_dir = example_dir + "/node_modules/sync-rpc/lib"
   patch_file = base.get_script_dir() + "/../tools/linux/sync-rpc.patch"
-  if ("linux" == base.host_platform()):  
+  if ("linux" == base.host_platform() or "freebsd" == base.host_platform()):
     base.cmd_in_dir(sync_rpc_lib_dir, "patch", ["-N", "-i", patch_file])
   if ("windows" == base.host_platform()):
     patch_exe_dir = base.git_dir() + "/usr/bin"
     base.cmd_in_dir(patch_exe_dir, "patch.exe", ["-N", "-d", sync_rpc_lib_dir, "-i", patch_file])
-  base.cmd_in_dir(example_dir, "pkg", [".", "-t", pkg_target, "-o", "example"])
+  base.cmd_in_dir(example_dir, pkgBin, [".", "-t", pkg_target, "-o", "example"])
 
 def build_server_develop():
   server_dir = base.get_script_dir() + "/../../server"
