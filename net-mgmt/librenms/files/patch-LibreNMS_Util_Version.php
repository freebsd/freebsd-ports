--- LibreNMS/Util/Version.php.orig	2021-05-21 10:09:00 UTC
+++ LibreNMS/Util/Version.php
@@ -92,7 +92,7 @@ class Version
 
     public static function python()
     {
-        $proc = new Process(['python3', '--version']);
+        $proc = new Process(['%%LOCALBASE%%/bin/python3', '--version']);
         $proc->run();
 
         if ($proc->getExitCode() !== 0) {
