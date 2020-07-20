--- LibreNMS/Util/Version.php.orig	2020-07-20 20:50:27 UTC
+++ LibreNMS/Util/Version.php
@@ -92,7 +92,7 @@ class Version
 
     public static function python()
     {
-        $proc = new Process(['python3', '--version']);
+        $proc = new Process(['/usr/local/bin/python3', '--version']);
         $proc->run();
 
         if ($proc->getExitCode() !== 0) {
