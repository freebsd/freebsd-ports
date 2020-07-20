--- LibreNMS/Validations/Python.php.orig	2020-07-20 21:06:40 UTC
+++ LibreNMS/Validations/Python.php
@@ -51,7 +51,9 @@ class Python extends BaseValidation
 
         $this->checkVersion($validator, $version);
         $this->checkPipVersion($validator, $version);
-        $this->checkExtensions($validator);
+        # We've installed from a FreeBSD package.
+        # Wwe aren't using pip
+        #$this->checkExtensions($validator);
     }
 
     private function checkVersion(Validator $validator, $version)
