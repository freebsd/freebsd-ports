--- htdocs/login_form.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/login_form.php
@@ -19,11 +19,11 @@ echo '<br />';
 $isHTTPS = false;
 
 # Check if the current connection is encrypted
-if (isset($_SERVER['HTTPS']) && strtolower($_SERVER['HTTPS']) == 'on') {
+if (isset($_SERVER['HTTPS']) && strtolower((string) $_SERVER['HTTPS']) == 'on') {
         $isHTTPS = true;
 }
 # Check if a proxy server downstream does encryption for us
-elseif (!empty($_SERVER['HTTP_X_FORWARDED_PROTO']) && strtolower($_SERVER['HTTP_X_FORWARDED_PROTO']) == 'https' || !empty($_SERVER['HTTP_X_FORWARDED_SSL']) && strtolower($_SERVER['HTTP_X_FORWARDED_SSL'])
+elseif (!empty($_SERVER['HTTP_X_FORWARDED_PROTO']) && strtolower((string) $_SERVER['HTTP_X_FORWARDED_PROTO']) == 'https' || !empty($_SERVER['HTTP_X_FORWARDED_SSL']) && strtolower($_SERVER['HTTP_X_FORWARDED_SSL'])
 == 'on') {
         $isHTTPS = true;
 }
