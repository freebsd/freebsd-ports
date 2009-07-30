--- ./program/include/rcube_message.php.orig	2009-07-30 14:35:17.000000000 +0200
+++ ./program/include/rcube_message.php	2009-07-30 14:35:35.000000000 +0200
@@ -373,7 +373,7 @@
 
         // part is file/attachment
         else if ($mail_part->disposition == 'attachment' || $mail_part->disposition == 'inline' ||
-                 $mail_part->headers['content-id'] || (empty($mail_part->disposition) && $mail_part->filename)) {
+                 $mail_part->headers['content-id'] || $mail_part->filename) {
           // skip apple resource forks
           if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile')
             continue;
