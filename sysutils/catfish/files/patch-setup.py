--- setup.py.orig	2021-07-20 10:04:29 UTC
+++ setup.py
@@ -199,8 +199,7 @@ class InstallAndUpdateDataDirectory(DistUtilsExtra.aut
 
             data_dir = os.path.join(self.prefix, 'share', 'catfish', '')
             script_path = os.path.join(self.prefix, 'bin')
-
-        if using_pip:
+        elif using_pip:
             target_data = os.path.relpath(self.install_data) + os.sep
             target_pkgdata = os.path.join(site.getuserbase(), 'share', 'catfish')
             target_scripts = os.path.join(site.getuserbase(), 'bin')
