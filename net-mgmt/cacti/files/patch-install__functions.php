--- install/functions.php.orig	2019-01-03 02:14:26 UTC
+++ install/functions.php
@@ -528,7 +528,7 @@ function install_file_paths() {
 	/* log file path */
 	$input['path_cactilog'] = $settings['path']['path_cactilog'];
 	if (empty($input['path_cactilog']['default'])) {
-		$input['path_cactilog']['default'] = $config['base_path'] . '/log/cacti.log';
+		$input['path_cactilog']['default'] = '/var/log/cacti/log';
 	}
 
 	/* stderr log file path */
