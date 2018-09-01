--- includes/common.php.orig	2018-08-04 20:07:12 UTC
+++ includes/common.php
@@ -1157,6 +1157,10 @@ function version_info($remote = false)
         $output['local_sha']    = $local_sha;
         $output['local_date']   = $local_date;
         $output['local_branch'] = rtrim(`git rev-parse --abbrev-ref HEAD`);
+    } else {
+        $output['local_ver']  = '%%PORTVERSION%%';
+        # obtained via git show --pretty='%H|%ct' -s %%PORTVERSION%%
+        $output['local_date'] = %%RELEASE_TIMESTAMP%%;
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
