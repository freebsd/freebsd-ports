--- LibreNMS/Validations/Programs.php.orig	2020-07-10 19:56:16 UTC
+++ LibreNMS/Validations/Programs.php
@@ -96,6 +96,7 @@ class Programs extends BaseValidation
 
     private function failFping($validator, $cmd, $output)
     {
+        $validator->warn("fping FAILURES can be ignored if running LibreNMS in a jail without ::1. You may want to test it manually: fping ::1");
         $validator->fail(
             "$cmd could not be executed. $cmd must have CAP_NET_RAW capability (getcap) or suid. Selinux exclusions may be required.\n ($output)"
         );
