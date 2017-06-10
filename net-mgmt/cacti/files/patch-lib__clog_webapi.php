--- lib/clog_webapi.php.orig	2017-06-05 03:49:49 UTC
+++ lib/clog_webapi.php
@@ -40,7 +40,7 @@ function clog_purge_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	if (file_exists($logfile)) {
@@ -70,7 +70,7 @@ function clog_view_logfile() {
 			$logfile = $requestedFile;
 		}
 	} elseif ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* ================= input validation and session storage ================= */
