--- includes/common.php.orig	2017-01-15 20:50:30.075142000 +0000
+++ includes/common.php	2017-01-15 20:42:35.634055000 +0000
@@ -1110,10 +1110,10 @@
         curl_setopt($api, CURLOPT_RETURNTRANSFER, 1);
         $output['github'] = json_decode(curl_exec($api), true);
     }
-    list($local_sha, $local_date) = explode('|', rtrim(`git show --pretty='%H|%ct' -s HEAD`));
-    $output['local_sha']    = $local_sha;
+#    list($local_sha, $local_date) = explode('|', rtrim(`git show --pretty='%H|%ct' -s HEAD`));
+    $output['local_sha']    = '%%PORTVERSION%%';
     $output['local_date']   = $local_date;
-    $output['local_branch'] = rtrim(`git rev-parse --abbrev-ref HEAD`);
+#    $output['local_branch'] = rtrim(`git rev-parse --abbrev-ref HEAD`);
 
     $output['db_schema']   = dbFetchCell('SELECT version FROM dbSchema');
     $output['php_ver']     = phpversion();
