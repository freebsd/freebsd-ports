--- install/functions.php.orig	2019-07-15 19:23:30 UTC
+++ install/functions.php
@@ -538,7 +538,7 @@ function install_file_paths() {
 	}
 
 	if (empty($input['path_cactilog']['default'])) {
-		$input['path_cactilog']['default'] = $config['base_path'] . '/log/cacti.log';
+		$input['path_cactilog']['default'] = '/var/log/cacti/log';
 	}
 
 	/* stderr log file path */
