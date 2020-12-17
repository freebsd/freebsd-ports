--- utilities.php.orig	2020-11-30 18:19:51 UTC
+++ utilities.php
@@ -1043,7 +1043,7 @@ function utilities_view_logfile() {
 	}
 	
 	if ($logfile == '') {
-		$logfile = 'cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 	
 	$logname = '';
@@ -1372,7 +1372,7 @@ function utilities_clear_logfile() {
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	html_start_box(__('Clear Cacti Log'), '100%', '', '3', 'center', '');
