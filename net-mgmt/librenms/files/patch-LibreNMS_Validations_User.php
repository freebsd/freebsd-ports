--- LibreNMS/Validations/User.php.orig	2020-04-28 03:52:42 UTC
+++ LibreNMS/Validations/User.php
@@ -85,6 +85,7 @@ class User extends BaseValidation
                 "sudo chmod -R ug=rwX $rrd_dir $log_dir $dir/bootstrap/cache/ $dir/storage/",
             ];
 
+            if (!Config::get('installed_from_package')) {
             $find_result = rtrim(`find $dir \! -user $lnms_username -o \! -group $lnms_groupname 2> /dev/null`);
             if (!empty($find_result)) {
                 // Ignore files created by the webserver
@@ -137,6 +138,7 @@ class User extends BaseValidation
                 $validator->result(ValidationResult::fail(
                     'Some folders have incorrect file permissions, this may cause issues.'
                 )->setFix($fix)->setList('Files', explode(PHP_EOL, $incorrect)));
+            }
             }
         } else {
             $validator->warn("You don't have \$config['user'] set, this most likely needs to be set to librenms");
