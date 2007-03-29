--- cacti-0.8.6j/include/config.php.orig	Fri Jan  6 00:27:51 2006
+++ cacti-0.8.6j/include/config.php	Fri Jan  6 00:28:39 2006
@@ -24,7 +24,11 @@
  +-------------------------------------------------------------------------+
 */
 
-/* make sure these values refect your actual database/host/user/password */
+/*
+ * these are default values. do not change them. set your actual
+ * database/host/user/password in db-settings.php file instead.
+ *
+ */
 $database_type = "mysql";
 $database_default = "cacti";
 $database_hostname = "localhost";
@@ -64,6 +68,9 @@
 $config["base_path"] = strtr(ereg_replace("(.*)[\/\\]include", "\\1", dirname(__FILE__)), "\\", "/");
 $config["library_path"] = ereg_replace("(.*[\/\\])include", "\\1lib", dirname(__FILE__));
 $config["include_path"] = dirname(__FILE__);
+ 
+/* load user defined DB settings */
+include($config["include_path"] . "/db-settings.php");
 
 /* colors */
 $colors["dark_outline"] = "454E53";
