--- LibreNMS/Validations/Programs.php.orig	2020-04-28 03:52:42 UTC
+++ LibreNMS/Validations/Programs.php
@@ -74,6 +74,7 @@ class Programs extends BaseValidation
             return;
         }
 
+        $validator->warn("fping FAILURES can be ignored if running LibreNMS in a jail without ::1. You may want to test it manually: fping ::1");
         $validator->fail(
             "$bin could not be executed. $bin must have CAP_NET_RAW capability (getcap) or suid. Selinux exlusions may be required.\n ($output)"
         );
