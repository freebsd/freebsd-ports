--- lib/functions.php.orig	2019-01-03 02:14:26 UTC
+++ lib/functions.php
@@ -818,7 +818,7 @@ function cacti_log_file() {
 	global $config;
 	$logfile        = read_config_option('path_cactilog');
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 	$config['log_path'] = $logfile;
 	return $logfile;
