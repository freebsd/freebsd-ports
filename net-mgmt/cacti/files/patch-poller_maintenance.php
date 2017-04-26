--- poller_maintenance.php.orig	2017-04-24 03:25:50.000000000 +0100
+++ poller_maintenance.php	2017-04-25 14:27:06.327800000 +0100
@@ -175,13 +175,13 @@
 
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
