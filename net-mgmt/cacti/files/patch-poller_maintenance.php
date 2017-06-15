--- poller_maintenance.php.orig	2017-02-04 14:23:37.951265000 +0000
+++ poller_maintenance.php	2017-02-04 14:24:49.403929000 +0000
@@ -172,10 +172,10 @@
  */
 function logrotate_rotatenow () {
 	global $config;
-	$log = $config['base_path'] . '/log/cacti.log';
+	$log = '/var/log/cacti/log';
 	set_config_option('logrotate_lastrun', time());
 	clearstatcache();
-	if (is_writable($config['base_path'] . '/log/') && is_writable($log)) {
+	if (is_writable('/var/log/cacti') && is_writable($log)) {
 		$perms = octdec(substr(decoct( fileperms($log) ), 2));
 		$owner = fileowner($log);
 		$group = filegroup($log);
