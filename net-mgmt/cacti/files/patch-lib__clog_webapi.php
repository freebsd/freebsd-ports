--- lib/clog_webapi.php.orig	2017-08-13 04:06:37 UTC
+++ lib/clog_webapi.php
@@ -42,7 +42,7 @@ function clog_purge_logfile() {
 	$logfile   = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	$purgefile = dirname($logfile) . '/' . get_nfilter_request_var('filename');
@@ -85,7 +85,7 @@ function clog_view_logfile() {
 			$logfile = $requestedFile;
 		}
 	} elseif ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* ================= input validation and session storage ================= */
