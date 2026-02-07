--- lib/ExchAuth.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/ExchAuth.class.php
@@ -55,7 +55,7 @@ class ExchAuth {
 	* @param string $domain
 	* @return boolean
 	*/
-	function authUser($username, $password, $domain) {
+	function __construct($username, $password, $domain) {
 		
 		$fulluser = $domain.'/'.$username;
 		$mbox = imap_open('{'.$this->exchHost.'/imap}Inbox', $fulluser, $password);
