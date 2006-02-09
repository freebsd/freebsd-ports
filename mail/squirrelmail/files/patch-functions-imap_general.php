diff -u -r1.140.2.29 -r1.140.2.30
--- functions/imap_general.php	2005/05/20 10:37:34	1.140.2.29
+++ functions/imap_general.php	2005/11/27 08:32:37	1.140.2.30
@@ -8,7 +8,7 @@
  *
  * This implements all functions that do general IMAP functions.
  *
- * @version $Id: imap_general.php,v 1.140.2.29 2005/05/20 10:37:34 kink Exp $
+ * @version $Id: imap_general.php,v 1.140.2.30 2005/11/27 08:32:37 tokul Exp $
  * @package squirrelmail
  * @subpackage imap
  */
@@ -888,7 +888,7 @@
  * Saves a message to a given folder -- used for saving sent messages
  */
 function sqimap_append ($imap_stream, $sent_folder, $length) {
-    fputs ($imap_stream, sqimap_session_id() . " APPEND \"$sent_folder\" (\\Seen) \{$length}\r\n");
+    fputs ($imap_stream, sqimap_session_id() . " APPEND \"$sent_folder\" (\\Seen) {".$length."}\r\n");
     $tmp = fgets ($imap_stream, 1024);
     sqimap_append_checkresponse($tmp, $sent_folder);
 }
