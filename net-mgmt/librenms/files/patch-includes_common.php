--- includes/common.php.orig	2020-07-10 19:56:16 UTC
+++ includes/common.php
@@ -1004,6 +1004,10 @@ function version_info($remote = false)
         $output['local_sha']    = $local_sha;
         $output['local_date']   = $local_date;
         $output['local_branch'] = rtrim(`git rev-parse --abbrev-ref HEAD`);
+    } else {
+        $output['local_ver']  = '%%PORTVERSION%%';
+        # obtained via git show --pretty='%H|%ct' -s %%PORTVERSION%%
+        $output['local_date'] = %%RELEASE_TIMESTAMP%%;
     }
     $output['db_schema']   = vsprintf('%s (%s)', $version->database());
     $output['php_ver']     = phpversion();
