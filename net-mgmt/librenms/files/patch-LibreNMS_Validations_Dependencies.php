--- LibreNMS/Validations/Dependencies.php.orig	2018-10-24 19:04:18 UTC
+++ LibreNMS/Validations/Dependencies.php
@@ -38,6 +38,9 @@ class Dependencies extends BaseValidatio
      */
     public function validate(Validator $validator)
     {
+        $validator->ok("Installed from package; no Composer required");
+        return;
+
         $composer_output = trim(shell_exec($validator->getBaseDir() . '/scripts/composer_wrapper.php --version'));
         $found = preg_match(
             '/Composer.*(\d+\.\d+\.\d+(-RC\d*|-beta\d?|-alpha\d+)?)/',
