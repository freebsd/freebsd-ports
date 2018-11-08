--- LibreNMS/Validations/Programs.php.orig	2018-10-17 10:33:28 UTC
+++ LibreNMS/Validations/Programs.php
@@ -73,6 +73,7 @@ class Programs extends BaseValidation
             return;
         }
 
+        $validator->warn("fping FAILURES can be ignored if running LibreNMS in a jail without ::1. You may want to test it manually: fping ::1");
         $validator->fail(
             "$bin could not be executed. $bin must have CAP_NET_RAW capability (getcap) or suid. Selinux exlusions may be required.\n ($output)"
         );
