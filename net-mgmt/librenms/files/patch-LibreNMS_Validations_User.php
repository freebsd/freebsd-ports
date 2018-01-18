--- LibreNMS/Validations/User.php.orig	2017-12-31 20:48:36 UTC
+++ LibreNMS/Validations/User.php
@@ -62,29 +62,7 @@ class User implements ValidationGroup
 
 
         // Let's test the user configured if we have it
-        if (Config::has('user')) {
-            $dir = Config::get('install_dir');
-
-            $find_result = rtrim(`find $dir \! -user $lnms_username -o \! -group $lnms_groupname &> /dev/null`);
-            if (!empty($find_result)) {
-                // Ignore the two logs that may be created by the
-                $files = array_diff(explode(PHP_EOL, $find_result), array(
-                    "$dir/logs/error_log",
-                    "$dir/logs/access_log",
-                ));
-
-                if (!empty($files)) {
-                    $result = ValidationResult::fail(
-                        "We have found some files that are owned by a different user than $lnms_username, this " .
-                        'will stop you updating automatically and / or rrd files being updated causing graphs to fail.'
-                    )
-                        ->setFix("chown -R $lnms_username:$lnms_groupname $dir")
-                        ->setList('Files', $files);
-
-                    $validator->result($result);
-                }
-            }
-        } else {
+        if (!Config::has('user')) {
             $validator->warn("You don't have \$config['user'] set, this most likely needs to be set to librenms");
         }
 
