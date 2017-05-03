--- lib/clog_webapi.php.orig	2017-04-26 00:30:09 UTC
+++ lib/clog_webapi.php
@@ -40,7 +40,7 @@ function clog_purge_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	if (file_exists($logfile)) {
@@ -64,7 +64,7 @@ function clog_view_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* helps determine output color */
