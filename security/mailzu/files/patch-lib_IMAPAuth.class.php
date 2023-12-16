--- lib/IMAPAuth.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/IMAPAuth.class.php
@@ -36,7 +36,7 @@ class IMAPAuth {
 	* Constructor to initialize object
 	* @param none
 	*/
-	function IMAPAuth() {
+	function __construct() {
 		global $conf;
 
 		$this->imapHosts = $conf['auth']['imap_hosts'];
