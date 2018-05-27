--- setup.py.orig	2017-11-12 01:10:33 UTC
+++ setup.py
@@ -235,7 +235,10 @@ class InstallData(install_data):
         data_dir = get_command_obj("install_data").install_dir
         data_dir = os.path.join(data_dir, "share", "gaupol")
         files = glob.glob("{}/extensions/*/*.py".format(data_dir))
-        distutils.util.byte_compile(files, optimize, self.force, self.dry_run)
+        distutils.util.byte_compile(files, optimize, self.force,
+                                    base_dir=%%PREFIX%%,
+                                    prefix=%%STAGEDIR%%,
+                                    dry_run=self.dry_run)
 
     def __generate_linguas(self):
         """Generate LINGUAS file needed by msgfmt."""
