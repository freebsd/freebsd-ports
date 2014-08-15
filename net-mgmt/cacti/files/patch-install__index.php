--- ./install/index.php.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./install/index.php	2014-08-11 18:45:19.000000000 -0700
@@ -267,7 +267,7 @@
 if (config_value_exists("path_cactilog")) {
 	$input["path_cactilog"]["default"] = read_config_option("path_cactilog");
 } else {
-	$input["path_cactilog"]["default"] = $config["base_path"] . "/log/cacti.log";
+	$input["path_cactilog"]["default"] = "/var/log/cacti/cacti.log";
 }
 
 /* SNMP Version */
