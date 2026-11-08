-- Don't install the launcher script by default
-- The wheel also installs the pymol entry point and both write bin/pymol, which makes the installation fail

--- setup.py.orig	2026-10-18 20:41:44 UTC
+++ setup.py
@@ -413,7 +413,7 @@ class install_pymol(install):
 class install_pymol(install):
     pymol_path = None
     bundled_pmw = False
-    no_launcher = False
+    no_launcher = True
 
     user_options = install.user_options + [
         ("pymol-path=", None, "PYMOL_PATH"),
