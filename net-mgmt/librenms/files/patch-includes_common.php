--- includes/common.php.orig	2017-01-29 06:54:29 UTC
+++ includes/common.php
@@ -1095,10 +1095,8 @@ function version_info($remote = true)
             curl_setopt($api, CURLOPT_RETURNTRANSFER, 1);
             $output['github'] = json_decode(curl_exec($api), true);
         }
-        list($local_sha, $local_date) = explode('|', rtrim(`git show --pretty='%H|%ct' -s HEAD`));
-        $output['local_sha']    = $local_sha;
+        $output['local_sha']    = '%%PORTVERSION%%';
         $output['local_date']   = $local_date;
-        $output['local_branch'] = rtrim(`git rev-parse --abbrev-ref HEAD`);
     }
     $output['db_schema']   = dbFetchCell('SELECT version FROM dbSchema');
     $output['php_ver']     = phpversion();
