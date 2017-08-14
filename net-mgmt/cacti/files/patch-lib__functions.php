--- lib/functions.php.orig	2017-08-13 04:06:37 UTC
+++ lib/functions.php
@@ -615,7 +615,7 @@ function cacti_log($string, $output = false, $environ 
 	/* Log to Logfile */
 	if (($logdestination == 1 || $logdestination == 2) && read_config_option('log_verbosity') != POLLER_VERBOSITY_NONE) {
 		if ($logfile == '') {
-			$logfile = $config['base_path'] . '/log/cacti.log';
+			$logfile = '/var/log/cacti/log';
 		}
 
 		/* echo the data to the log (append) */
