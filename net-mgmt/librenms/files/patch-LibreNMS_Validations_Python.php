--- LibreNMS/Validations/Python.php.orig	2020-07-10 19:56:16 UTC
+++ LibreNMS/Validations/Python.php
@@ -50,8 +50,10 @@ class Python extends BaseValidation
         }
 
         $this->checkVersion($validator, $version);
-        $this->checkPipVersion($validator, $version);
-        $this->checkExtensions($validator);
+# We've installed from a FreeBSD package.
+# We aren't using pip
+#       $this->checkPipVersion($validator, $version);
+#       $this->checkExtensions($validator);
     }
 
     private function checkVersion(Validator $validator, $version)
