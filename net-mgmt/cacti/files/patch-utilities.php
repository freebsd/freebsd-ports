--- utilities.php.orig	2017-04-26 00:30:09 UTC
+++ utilities.php
@@ -872,7 +872,7 @@ function utilities_view_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* helps determine output color */
@@ -1155,7 +1155,7 @@ function utilities_clear_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	html_start_box(__('Clear Cacti Log'), '100%', '', '3', 'center', '');
