--- include/config.php.orig	Tue Jun 21 04:46:46 2005
+++ include/config.php	Tue Jun 21 16:27:29 2005
@@ -24,13 +24,6 @@
  +-------------------------------------------------------------------------+
 */
 
-/* make sure these values refect your actual database/host/user/password */
-$database_type = "mysql";
-$database_default = "cacti";
-$database_hostname = "localhost";
-$database_username = "cactiuser";
-$database_password = "cactiuser";
-
 /* ----- you probably do not need to change anything below this line ----- */
 $config = array();
 
@@ -44,6 +37,9 @@
 $config["base_path"] = ereg_replace("(.*)[\/\\]include", "\\1", dirname(__FILE__));
 $config["library_path"] = ereg_replace("(.*[\/\\])include", "\\1lib", dirname(__FILE__));
 $config["include_path"] = dirname(__FILE__);
+
+/* load user defined DB settings */
+include($config["include_path"] . "/db-settings.php");
 
 /* colors */
 $colors["dark_outline"] = "454E53";
