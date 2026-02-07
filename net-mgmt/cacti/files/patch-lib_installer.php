--- lib/installer.php.orig	2021-06-01 00:15:30.652736000 +0000
+++ lib/installer.php	2021-06-01 00:16:32.509002000 +0000
@@ -3404,7 +3404,7 @@
 
 		$page_nr = 1;
 		$total_rows = 500;
-		$logcontents = tail_file($config['base_path'] . '/log/cacti.log', 100, -1, ' INSTALL:' , $page_nr, $total_rows);
+		$logcontents = tail_file('/var/log/cacti/log', 100, -1, ' INSTALL:' , $page_nr, $total_rows);
 
 		$output_log = '';
 		foreach ($logcontents as $logline) {
