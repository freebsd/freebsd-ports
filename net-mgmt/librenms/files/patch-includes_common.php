--- includes/common.php.orig	2018-08-04 20:07:12 UTC
+++ includes/common.php
@@ -1157,6 +1157,10 @@ function version_info($remote = false)
         $output['local_sha']    = $local_sha;
         $output['local_date']   = $local_date;
         $output['local_branch'] = rtrim(`git rev-parse --abbrev-ref HEAD`);
+    } else {
+        $output['local_ver']  = '1.42.01';
+        # obtained via git show --pretty='%H|%ct' -s 1.42.01
+        $output['local_date'] = 1533413232;
     }
     $output['db_schema']   = dbIsConnected() ? get_db_schema() : '?';
     $output['php_ver']     = phpversion();
@@ -1713,6 +1717,12 @@ function set_numeric($value, $default = 
 
 function check_git_exists()
 {
+    global $config;
+
+    if (!empty($config['installed_from_package'])) {
+        return false;
+    }
+
     exec('git > /dev/null 2>&1', $response, $exit_code);
     if ($exit_code === 1) {
         return true;
