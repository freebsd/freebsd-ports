--- poller_maintenance.php.orig	2018-02-26 01:12:04 UTC
+++ poller_maintenance.php
@@ -223,7 +223,7 @@ function logrotate_rotatenow () {
 
 	$log = read_config_option('path_cactilog');
 	if ($log == '') {
-		$log = $config['base_path'] . '/log/cacti.log';
+		$log = '/var/log/cacti/log';
 	}
 
 	$run_time = time();
