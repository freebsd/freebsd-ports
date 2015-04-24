--- install/index.php.bak	2015-03-12 03:12:05.409276443 -0700
+++ install/index.php	2015-03-12 03:14:17.596295374 -0700
@@ -267,7 +267,7 @@
 if (config_value_exists("path_cactilog")) {
 	$input["path_cactilog"]["default"] = read_config_option("path_cactilog");
 } else {
-	$input["path_cactilog"]["default"] = $config["base_path"] . "/log/cacti.log";
+	$input["path_cactilog"]["default"] = "/var/log/cacti/log";
 }
 
 /* SNMP Version */
