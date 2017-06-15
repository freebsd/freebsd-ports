--- utilities.php.orig	2017-02-04 14:25:11.346062000 +0000
+++ utilities.php	2017-02-04 14:25:39.435371000 +0000
@@ -869,7 +869,7 @@
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = $config['base_path'] . '/log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	/* helps determine output color */
@@ -1149,7 +1149,7 @@
 	$logfile = read_config_option('path_cactilog');
 
 	if ($logfile == '') {
-		$logfile = './log/cacti.log';
+		$logfile = '/var/log/cacti/log';
 	}
 
 	html_start_box(__('Clear Cacti Log'), '100%', '', '3', 'center', '');
