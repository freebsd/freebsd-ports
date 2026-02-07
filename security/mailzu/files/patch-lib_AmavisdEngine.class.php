--- lib/AmavisdEngine.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/AmavisdEngine.class.php
@@ -48,7 +48,7 @@ class AmavisdEngine {
 	* $param none
 	* $return object Amavisd object
 	*/
-	function AmavisdEngine($host) {
+	function __construct($host) {
 
 		$this->socket = new Net_Socket();
 		$this->port = $GLOBALS['conf']['amavisd']['spam_release_port'];
