--- lib/functions.php.orig	2017-02-04 14:16:43.886716000 +0000
+++ lib/functions.php	2017-02-04 14:22:18.219392000 +0000
@@ -649,7 +649,7 @@
 	/* Log to Logfile */
 	if ((($logdestination == 1) || ($logdestination == 2)) && (read_config_option('log_verbosity') != POLLER_VERBOSITY_NONE)) {
 		if ($logfile == '') {
-			$logfile = $config['base_path'] . '/log/cacti.log';
+			$logfile = '/var/log/cacti/log';
 		}
 
 		/* echo the data to the log (append) */
