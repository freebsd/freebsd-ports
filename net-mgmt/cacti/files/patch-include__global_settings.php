--- include/global_settings.php.orig	2017-02-04 14:13:42.140386000 +0000
+++ include/global_settings.php	2017-02-04 14:20:35.592474000 +0000
@@ -135,9 +135,9 @@
 			),
 		'path_cactilog' => array(
 			'friendly_name' => __('Cacti Log Path'),
-			'description' => __('The path to your Cacti log file (if blank, defaults to <path_cacti>/log/cacti.log)'),
+			'description' => __('The path to your Cacti log file (if blank, defaults to /var/log/cacti/log)'),
 			'method' => 'filepath',
-			'default' => $config['base_path'] . '/log/cacti.log',
+			'default' => '/var/log/cacti/log',
 			'max_length' => '255'
 			),
 		'logrotate_enabled' => array(
