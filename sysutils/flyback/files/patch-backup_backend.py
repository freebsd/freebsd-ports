--- backup_backend.py.orig	2007-11-15 07:22:16.000000000 +0100
+++ backup_backend.py	2008-01-21 22:17:40.000000000 +0100
@@ -229,7 +229,7 @@
 
         if latest_backup_dir:
             last_backup = self.parent_backup_dir +'/'+ latest_backup_dir.strftime(BACKUP_DIR_DATE_FORMAT)
-            self.run_cmd_output_gui("cp -al '%s' '%s'" % (last_backup, new_backup))
+            self.run_cmd_output_gui("cp -RPpl '%s' '%s'" % (last_backup, new_backup))
             self.run_cmd_output_gui("chmod u+w '%s'" % new_backup)
         
         for dir in self.included_dirs:
