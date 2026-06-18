--- conf/confpetsc.py.orig	2026-04-12 03:48:08 UTC
+++ conf/confpetsc.py
@@ -694,7 +694,6 @@ class build_ext(_build_ext):
             (config_file, config_data),
             msg='writing %s' % config_file,
             verbose=self.verbose,
-            dry_run=self.dry_run,
         )
 
     def get_config_data(self, arch_list):
