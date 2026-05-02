--- setup.py.orig	2026-04-13 19:35:05 UTC
+++ setup.py
@@ -102,12 +102,10 @@ class Clean(clean):
             for targets in [glob.glob(x.strip()) for x in f]:
                 for target in filter(os.path.isdir, targets):
                     log.info("removing {}".format(target))
-                    if not self.dry_run:
-                        shutil.rmtree(target)
+                    shutil.rmtree(target)
                 for target in filter(os.path.isfile, targets):
                     log.info("removing {}".format(target))
-                    if not self.dry_run:
-                        os.remove(target)
+                    os.remove(target)
 
 
 class Distribution(distribution):
@@ -219,7 +217,9 @@ class InstallData(install_data):
         data_dir = get_command_obj("install_data").install_dir
         data_dir = os.path.join(data_dir, "share", "gaupol")
         files = glob.glob("{}/extensions/*/*.py".format(data_dir))
-        distutils.util.byte_compile(files, optimize, self.force, self.dry_run)
+        distutils.util.byte_compile(files, optimize, self.force,
+                                    base_dir=%%PREFIX%%,
+                                    prefix=%%STAGEDIR%%,)
         # Figure out paths of the compiled files and add them to
         # self.outfiles so that 'setup.py --record' works correctly.
         def get_cache_pattern(path):
