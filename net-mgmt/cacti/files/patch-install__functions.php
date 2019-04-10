--- install/functions.php.orig	2019-03-30 23:40:23 UTC
+++ install/functions.php
@@ -533,7 +533,7 @@ function install_file_paths() {
 	if (!config_value_exists('path_cactilog')) {
 		$input['path_cactilog'] = $settings['path']['path_cactilog'];
 		if (empty($input['path_cactilog']['default'])) {
-			$input['path_cactilog']['default'] = $config['base_path'] . '/log/cacti.log';
+			$input['path_cactilog']['default'] = '/var/log/cacti/log';
 		}
 	} else {
 		$input['path_cactilog'] = $settings['path']['path_cactilog'];
