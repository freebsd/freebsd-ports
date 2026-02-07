--- lib/DBAuth.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/DBAuth.class.php
@@ -81,7 +81,7 @@ class DBAuth {
 	* DBEngine constructor to initialize object
 	* @param none
 	*/
-	function DBAuth() {
+	function __construct() {
 		global $conf;
 
 		$this->dbType = $conf['auth']['dbType'];
