--- LibreNMS/Validations/User.php.orig	2018-10-17 10:33:28 UTC
+++ LibreNMS/Validations/User.php
@@ -71,6 +71,7 @@ class User extends BaseValidation
                 "sudo setfacl -d -m g::rwx $rrd_dir $log_dir $dir/bootstrap/cache/ $dir/storage/\n" .
                 "sudo chmod -R ug=rwX $rrd_dir $log_dir $dir/bootstrap/cache/ $dir/storage/\n";
 
+            if (!Config::get('installed_from_package')) {
             $find_result = rtrim(`find $dir \! -user $lnms_username -o \! -group $lnms_groupname 2> /dev/null`);
             if (!empty($find_result)) {
                 // Ignore files created by the webserver
@@ -124,6 +125,7 @@ class User extends BaseValidation
                     'Some folders have incorrect file permissions, this may cause issues.'
                 )->setFix($fix)->setList('Files', explode(PHP_EOL, $incorrect)));
             }
+            }
         } else {
             $validator->warn("You don't have \$config['user'] set, this most likely needs to be set to librenms");
         }
