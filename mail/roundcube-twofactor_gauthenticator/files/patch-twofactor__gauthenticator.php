--- twofactor_gauthenticator.php.orig	2023-11-26 19:11:04 UTC
+++ twofactor_gauthenticator.php
@@ -20,7 +20,8 @@ class twofactor_gauthenticator extends rcube_plugin 
 	private $_number_recovery_codes = 4;
 
         // relative to $config['log_dir']
-        private $_logs_file = 'log_errors_2FA.txt';
+        private $_logs_file = 'log_errors_2FA.txt';
+        private $_log_dir = '.';
 	
     function init() 
     {
