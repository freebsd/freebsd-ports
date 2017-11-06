--- poller_maintenance.php.orig	2017-08-13 04:06:37 UTC
+++ poller_maintenance.php
@@ -197,14 +197,14 @@ function logrotate_rotatenow () {
 
 	$log = read_config_option('path_cactilog');
 	if ($log == '') {
-		$log = $config['base_path'] . '/log/cacti.log';
+		$log = '/var/log/cacti/log';
 	}
 
 	set_config_option('logrotate_lastrun', time());
 
 	clearstatcache();
 
-	if (is_writable(dirname($log) . '/') && is_writable($log)) {
+	if (is_writable('/var/log/cacti') && is_writable($log)) {
 		$perms = octdec(substr(decoct( fileperms($log) ), 2));
 		$owner = fileowner($log);
 		$group = filegroup($log);
