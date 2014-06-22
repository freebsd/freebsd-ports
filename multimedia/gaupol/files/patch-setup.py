--- setup.py.orig	2011-09-11 16:26:55.000000000 +0200
+++ setup.py	2014-06-22 15:30:04.801515555 +0200
@@ -284,7 +284,9 @@
         data_dir = get_command_obj("install_data").install_dir
         data_dir = os.path.join(data_dir, "share", "gaupol")
         files = glob.glob("%s/extensions/*/*.py" % data_dir)
-        distutils.util.byte_compile(files, optimize, self.force, self.dry_run)
+        prefix = %%STAGEDIR%%
+        base_dir = %%PREFIX%%
+        distutils.util.byte_compile(files, optimize, self.force, prefix = prefix, base_dir = base_dir, dry_run = self.dry_run)
 
     def __get_desktop_file(self):
         """Return a tuple for translated desktop file."""
