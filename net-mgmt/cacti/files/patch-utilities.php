--- utilities.php.orig	2017-06-05 03:49:49 UTC
+++ utilities.php
@@ -877,7 +877,7 @@ function utilities_view_logfile() {
 			$logfile = $requestedFile;
 		}
 	} elseif ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* ================= input validation and session storage ================= */
@@ -1194,7 +1194,7 @@ function utilities_clear_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	html_start_box(__('Clear Cacti Log'), '100%', '', '3', 'center', '');
