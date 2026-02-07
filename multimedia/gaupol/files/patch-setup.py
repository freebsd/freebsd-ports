--- setup.py.orig	2018-05-27 20:40:27 UTC
+++ setup.py
@@ -232,7 +232,10 @@ class InstallData(install_data):
         data_dir = get_command_obj("install_data").install_dir
         data_dir = os.path.join(data_dir, "share", "gaupol")
         files = glob.glob("{}/extensions/*/*.py".format(data_dir))
-        distutils.util.byte_compile(files, optimize, self.force, self.dry_run)
+        distutils.util.byte_compile(files, optimize, self.force,
+                                    base_dir=%%PREFIX%%,
+                                    prefix=%%STAGEDIR%%,
+                                    dry_run=self.dry_run)
         # Figure out paths of the compiled files and add them to
         # self.outfiles so that 'setup.py --record' works correctly.
         def get_cache_pattern(path):
