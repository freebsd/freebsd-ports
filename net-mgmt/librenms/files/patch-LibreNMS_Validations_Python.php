--- LibreNMS/Validations/Python.php.orig	2026-11-16 16:05:23 UTC
+++ LibreNMS/Validations/Python.php
@@ -55,7 +55,7 @@ class Python extends BaseValidation
 
         $pip_output = (string) `pip3 --version 2>/dev/null`;
         if (empty($pip_output)) {
-            $validator->warn('pip3 is not available');
+            $validator->warn('pip3 is not available - it is not neeed when installing from package/port');
         } else {
             $this->checkPipVersion($validator, $pip_output, $version);
             $this->checkExtensions($validator);
