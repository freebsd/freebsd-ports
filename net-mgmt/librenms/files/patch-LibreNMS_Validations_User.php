--- LibreNMS/Validations/User.php.orig	2020-07-10 19:56:16 UTC
+++ LibreNMS/Validations/User.php
@@ -84,6 +84,7 @@ class User extends BaseValidation
                 "sudo chmod -R ug=rwX $rrd_dir $log_dir $dir/bootstrap/cache/ $dir/storage/",
             ];
 
+            if (!Config::get('installed_from_package')) {
             $find_result = rtrim(`find $dir \! -user $lnms_username -o \! -group $lnms_groupname 2> /dev/null`);
             if (!empty($find_result)) {
                 // Ignore files created by the webserver
@@ -117,6 +118,7 @@ class User extends BaseValidation
                     $validator->result($result);
                     return;
                 }
+            }
             }
         } else {
             $validator->warn("You don't have LIBRENMS_USER set, this most likely needs to be set to librenms");
