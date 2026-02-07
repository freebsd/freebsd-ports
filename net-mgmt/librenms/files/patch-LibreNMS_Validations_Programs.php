--- LibreNMS/Validations/Programs.php.orig	2021-05-21 10:48:49 UTC
+++ LibreNMS/Validations/Programs.php
@@ -99,7 +99,7 @@ class Programs extends BaseValidation
     {
         $validator->info('fping FAILURES can be ignored if running LibreNMS in a jail without ::1. You may want to test it manually: fping ::1');
         $validator->fail(
-            "$cmd could not be executed. $cmd must have CAP_NET_RAW capability (getcap) or suid. Selinux exclusions may be required.\n ($output)"
+            "$cmd could not be executed. $cmd must have CAP_NET_RAW capability (getcap) or suid. Selinux exclusions may be required.\n ($output). If there is no IPv6 address on your host, this is expected."
         );
 
         if ($getcap = $this->findExecutable('getcap')) {
