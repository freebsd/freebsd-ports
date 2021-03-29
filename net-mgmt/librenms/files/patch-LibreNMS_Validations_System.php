--- LibreNMS/Validations/System.php.orig	2021-03-25 16:28:19 UTC
+++ LibreNMS/Validations/System.php
@@ -39,7 +39,7 @@ class System extends BaseValidation
         $install_dir = $validator->getBaseDir();
 
         $lnms = `which lnms 2>/dev/null`;
-        if (empty($lnms)) {
+        if (empty($lnms) && !Config::get('installed_from_package')) {
             $validator->warn('Global lnms shortcut not installed. lnms command must be run with full path', "sudo ln -s $install_dir/lnms /usr/bin/lnms");
         }
 
@@ -50,7 +50,7 @@ class System extends BaseValidation
         }
 
         $rotation_file = '/etc/logrotate.d/librenms';
-        if (! file_exists($rotation_file)) {
+        if (! file_exists($rotation_file) && !Config::get('installed_from_package')) {
             $validator->warn('Log rotation not enabled, could cause disk space issues', "sudo cp $install_dir/misc/librenms.logrotate $rotation_file");
         }
     }
