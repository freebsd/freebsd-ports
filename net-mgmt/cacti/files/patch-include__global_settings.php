--- include/global_settings.php.bak	2015-03-12 03:08:59.333297709 -0700
+++ include/global_settings.php	2015-03-12 03:10:47.532302704 -0700
@@ -96,7 +96,7 @@
 			),
 		"path_cactilog" => array(
 			"friendly_name" => "Cacti Log File Path",
-			"description" => "The path to your Cacti log file (if blank, defaults to <path_cacti>/log/cacti.log)",
+			"description" => "The path to your Cacti log file (if blank, defaults to /var/log/cacti/log)",
 			"method" => "filepath",
 			"default" => $config["base_path"] . "/log/cacti.log",
 			"max_length" => "255"
