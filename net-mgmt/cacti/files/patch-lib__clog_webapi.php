--- lib/clog_webapi.php.orig	2017-02-04 14:22:42.713430000 +0000
+++ lib/clog_webapi.php	2017-02-04 14:23:10.949163000 +0000
@@ -40,7 +40,7 @@
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	if (file_exists($logfile)) {
@@ -64,7 +64,7 @@
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* helps determine output color */
