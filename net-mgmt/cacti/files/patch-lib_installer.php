--- lib/installer.php.orig	2019-07-26 03:05:22 UTC
+++ lib/installer.php
@@ -3216,7 +3216,7 @@ class Installer implements JsonSerializable {
 		global $config;
 
 		$page_nr = 1;
-		$logcontents = tail_file($config['base_path'] . '/log/cacti.log', 100, -1, ' INSTALL:' , $page_no, $total_rows);
+		$logcontents = tail_file('/var/log/cacti/log', 100, -1, ' INSTALL:' , $page_no, $total_rows);
 
 		$output_log = '';
 		foreach ($logcontents as $logline) {
