--- build_tools/tools/freebsd/automate.py.orig	2021-12-18 16:54:46 UTC
+++ build_tools/tools/freebsd/automate.py
@@ -0,0 +1,54 @@
+#!/usr/bin/env python
+
+import sys
+sys.path.append('../../scripts')
+import base
+import os
+import subprocess
+
+branch = "master"
+
+array_args = sys.argv[1:]
+array_modules = []
+
+base.set_env('QT_SELECT', 'qt5')
+if not base.is_dir("./qt"):
+    base.cmd("mkdir", ["qt",])
+    base.cmd("ln", ["-s", "/usr/local/lib/qt5", "qt/clang_64"])
+
+config = {}
+for arg in array_args:
+  if (0 == arg.find("--")):
+    indexEq = arg.find("=")
+    if (-1 != indexEq):
+      config[arg[2:indexEq]] = arg[indexEq + 1:]
+  else:
+    # XXX Currently only server has been checked for compilation under FreeBSD
+    if arg != 'server':
+    	print("module %s not supported yet under FreeBSD" % arg)
+    array_modules.append(arg)
+
+if ("branch" in config):
+  branch = config["branch"]
+
+print("---------------------------------------------")
+print("build branch: " + branch)
+print("---------------------------------------------")
+
+modules = " ".join(array_modules)
+# XXX Currently only server has been checked for compilation under FreeBSD
+if "" == modules:
+  modules = "server"
+
+print("---------------------------------------------")
+print("build modules: " + modules)
+print("---------------------------------------------")
+
+build_tools_params = ["--branch", branch,
+                      "--module", modules,
+                      "--update", "0",
+                      "--platform", "freebsd_64",
+                      "--qt-dir", os.getcwd() + "/qt"]
+
+base.cmd_in_dir("../..", "./configure.py", build_tools_params)
+base.cmd_in_dir("../..", "./make.py")
