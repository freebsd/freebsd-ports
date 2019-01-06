--- lib/installer.php.orig	2019-01-06 07:22:22 UTC
+++ lib/installer.php
@@ -3222,7 +3222,7 @@ class Installer implements JsonSerializable {
 
 	public static function getInstallLog() {
 		global $config;
-		$logcontents = tail_file($config['base_path'] . '/log/cacti.log', 100, -1, ' INSTALL:' , 1, $total_rows);
+		$logcontents = tail_file('/var/log/cacti/log', 100, -1, ' INSTALL:' , 1, $total_rows);
 
 		$output_log = '';
 		foreach ($logcontents as $logline) {
