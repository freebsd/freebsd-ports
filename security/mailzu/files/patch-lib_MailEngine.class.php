--- lib/MailEngine.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/MailEngine.class.php
@@ -48,7 +48,7 @@ class MailEngine {
 	* $param string The mail addr of the reader
 	* $return object MailEngine object
 	*/
-	function MailEngine($mail_id, $recip) {
+	function __construct($mail_id, $recip) {
 	  $this->recipient = $recip;
 	  $this->getRawContent($mail_id);
 	  $this->msg_error = false;
