--- lib/functions.php.orig	2017-04-26 00:30:09 UTC
+++ lib/functions.php
@@ -594,7 +594,7 @@ function cacti_log($string, $output = fa
 	/* Log to Logfile */
 	if (($logdestination == 1 || $logdestination == 2) && read_config_option('log_verbosity') != POLLER_VERBOSITY_NONE) {
 		if ($logfile == '') {
-			$logfile = $config['base_path'] . '/log/cacti.log';
+			$logfile = '/var/log/cacti/log';
 		}
 
 		/* echo the data to the log (append) */
