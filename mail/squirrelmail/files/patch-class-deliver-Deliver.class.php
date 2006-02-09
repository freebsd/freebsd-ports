diff -u -r1.18.2.22 -r1.18.2.23
--- class/deliver/Deliver.class.php	2005/06/03 19:51:11	1.18.2.22
+++ class/deliver/Deliver.class.php	2005/07/20 09:00:08	1.18.2.23
@@ -8,7 +8,7 @@
  * This contains all the functions needed to send messages through
  * a delivery backend.
  *
- * $Id: Deliver.class.php,v 1.18.2.22 2005/06/03 19:51:11 pdontthink Exp $
+ * $Id: Deliver.class.php,v 1.18.2.23 2005/07/20 09:00:08 tokul Exp $
  *
  * @author  Marc Groot Koerkamp
  * @package squirrelmail
@@ -447,7 +447,10 @@
 
         /* Insert the rest of the header fields */
         $header[] = 'Message-ID: '. $message_id . $rn;
-        if ($reply_rfc822_header->message_id) {
+        if (is_object($reply_rfc822_header) && 
+            isset($reply_rfc822_header->message_id) &&
+            $reply_rfc822_header->message_id) {
+            //if ($reply_rfc822_header->message_id) {
             $rep_message_id = $reply_rfc822_header->message_id;
         //        $this->strip_crlf($message_id);
             $header[] = 'In-Reply-To: '.$rep_message_id . $rn;
