--- utilities.php.orig	2017-08-13 04:06:37 UTC
+++ utilities.php
@@ -877,7 +877,7 @@ function utilities_view_logfile() {
 	}
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* ================= input validation and session storage ================= */
@@ -1199,7 +1199,7 @@ function utilities_clear_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	html_start_box(__('Clear Cacti Log'), '100%', '', '3', 'center', '');
