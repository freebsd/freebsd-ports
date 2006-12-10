diff -Nur sasql.orig/sasql_hooks.php sasql/sasql_hooks.php
--- sasql.orig/sasql_hooks.php	2006-11-09 21:29:21.000000000 +0100
+++ sasql/sasql_hooks.php	2006-12-10 12:13:12.000000000 +0100
@@ -74,23 +74,23 @@
 
     if (!sqimap_mailbox_exists($imap_stream, $mailbox)) {
       sqimap_mailbox_create($imap_stream, $mailbox, '');
-      if ($imap_server_type == 'cyrus') {
+      if ($imap_server_type == 'cyrus' || $imap_server_type == 'courier') {
 	$boxes = sqimap_mailbox_list($imap_stream);
       } else {
 	$boxes = sqimap_mailbox_list($imap_stream, true);
       }
-      session_register($boxes, 'boxesnew');
+      sqsession_register($boxes, 'boxesnew');
       // echo "<foo sasql created: $box />";
     }
 
     if (!sqimap_mailbox_is_subscribed($imap_stream, $mailbox)) {
       sqimap_subscribe($imap_stream, $mailbox);
-      if ($imap_server_type == 'cyrus') {
+      if ($imap_server_type == 'cyrus' || $imap_server_type == 'courier') {
 	$boxes = sqimap_mailbox_list($imap_stream);
       } else {
 	$boxes = sqimap_mailbox_list($imap_stream, true);
       }
-      session_register($boxes, 'boxesnew');
+      sqsession_register($boxes, 'boxesnew');
       // echo "<foo sasql subscried: $box />";
     }
   }
