--- config/init.php.orig	2007-06-14 19:00:15 UTC
+++ config/init.php
@@ -35,7 +35,7 @@
 session_start();
 
 // Turn off magic quotes (do not edit!)
-set_magic_quotes_runtime(0);
+// set_magic_quotes_runtime(0);
 
 $conf['app']['version'] = '0.8RC3';
 
