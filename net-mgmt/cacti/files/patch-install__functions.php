--- install/functions.php.orig	2017-04-26 00:30:09 UTC
+++ install/functions.php
@@ -421,7 +421,7 @@ function install_file_paths () {
 	if (config_value_exists('path_cactilog')) {
 		$input['path_cactilog']['default'] = read_config_option('path_cactilog');
 	} else {
-		$input['path_cactilog']['default'] = $config['base_path'] . '/log/cacti.log';
+		$input['path_cactilog']['default'] = '/var/log/cacti/log';
 	}
 
 	/* Theme */
