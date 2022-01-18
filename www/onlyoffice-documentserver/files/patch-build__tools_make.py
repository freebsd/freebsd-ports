--- build_tools/make.py.orig	2021-11-16 07:07:24 UTC
+++ build_tools/make.py
@@ -13,6 +13,7 @@ import build_js
 import build_server
 import deploy
 import make_common
+import os
 import develop
 
 # parse configuration
@@ -54,7 +55,17 @@ base.check_build_version(base_dir)
 # update
 if ("1" == config.option("update")):
   repositories = base.get_repositories()
-  base.update_repositories(repositories)
+#  base.update_repositories(repositories)
+
+  # Apply patches if available
+  patchdir = base_dir + '/patches/' + base.host_platform()
+  if os.path.exists(patchdir) :
+    for root, dirs, files in os.walk(patchdir) :
+      for filename in files :
+        tmpdir = base_dir + '/../' + filename.split('.', 1)[0]
+        print('Patching directory %s' % tmpdir)
+        base.cmd("patch", ["-d", tmpdir, "-i", patchdir + "/" + filename])
+
 
 base.configure_common_apps()
 
