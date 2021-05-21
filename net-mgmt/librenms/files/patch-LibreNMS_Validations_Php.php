--- LibreNMS/Validations/Php.php.orig	2020-07-20 21:19:29 UTC
+++ LibreNMS/Validations/Php.php
@@ -56,7 +56,7 @@ class Php extends BaseValidation
         }
 
         $web_version = PHP_VERSION;
-        $cli_version = rtrim(shell_exec('php -r "echo PHP_VERSION;"'));
+        $cli_version = rtrim(shell_exec('%%LOCALBASE%%/bin/php -r "echo PHP_VERSION;"'));
         if (version_compare($web_version, $cli_version, '!=')) {
             $validator->fail("PHP version of your webserver ($web_version) does not match the cli version ($cli_version)", "If you updated PHP recently, restart php-fpm or apache to switch to the new version");
         }
@@ -120,7 +120,7 @@ class Php extends BaseValidation
         $ini_tz = ini_get('date.timezone');
         $sh_tz = rtrim(shell_exec('date +%Z'));
         $php_tz = date('T');
-        $php_cli_tz = rtrim(shell_exec('php -r "echo date(\'T\');"'));
+        $php_cli_tz = rtrim(shell_exec('%%LOCALBASE%%/bin/php -r "echo date(\'T\');"'));
 
         if (empty($ini_tz)) {
             // make sure timezone is set
@@ -139,7 +139,7 @@ class Php extends BaseValidation
             // check if web and cli timezones match (this does nothing if validate.php is run on cli)
             // some distros have different php.ini for cli and the web server
             if ($sh_tz !== $php_cli_tz) {
-                $ini_file = rtrim(shell_exec('php -r "echo php_ini_loaded_file();"'));
+                $ini_file = rtrim(shell_exec('%%LOCALBASE%%/bin/php -r "echo php_ini_loaded_file();"'));
                 $validator->fail(
                     "The CLI php.ini ($php_cli_tz) timezone is different than your system's timezone ($sh_tz)",
                     "Edit your CLI ini file $ini_file and set the correct timezone ($sh_tz)."
