--- includes/common.php.orig	2018-10-17 10:33:28 UTC
+++ includes/common.php
@@ -1158,6 +1158,10 @@ function version_info($remote = false)
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
