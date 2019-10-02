--- lib/installer.php.orig	2019-09-29 18:36:29 UTC
+++ lib/installer.php
@@ -3226,7 +3226,7 @@ class Installer implements JsonSerializable {
 		global $config;
 
 		$page_nr = 1;
-		$logcontents = tail_file($config['base_path'] . '/log/cacti.log', 100, -1, ' INSTALL:' , $page_nr, $total_rows);
+		$logcontents = tail_file('/var/log/cacti/log', 100, -1, ' INSTALL:' , $page_nr, $total_rows);
 
 		$output_log = '';
 		foreach ($logcontents as $logline) {
