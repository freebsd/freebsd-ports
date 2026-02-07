--- read_mail.php.orig	2007-06-14 19:00:15 UTC
+++ read_mail.php
@@ -59,7 +59,7 @@ if ( ! $m->msg_found) {
 } else {
 
   echo '<form name="messages_process_form" action="messagesProcessing.php" method="POST">';
-  echo '  <input type="hidden" name="mail_id_array[]" value="' . $mail_id . '_' . $recip_email . '">';
+  echo '  <input type="hidden" name="mail_id_array[]" value="' . $mail_id . '__' . $recip_email . '">';
   echo '  <input type="hidden" name="query_string" value="' . $query_string . '">';
   printActionButtons(false);
   echo '</form>';
