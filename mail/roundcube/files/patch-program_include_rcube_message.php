--- program/include/rcube_message.php.orig	2009-08-27 10:08:27.000000000 +0200
+++ program/include/rcube_message.php	2009-09-07 17:47:43.000000000 +0200
@@ -384,7 +384,7 @@
 
         // part is a file/attachment
         else if (preg_match('/^(inline|attach)/', $mail_part->disposition) ||
-                 $mail_part->headers['content-id'] || (empty($mail_part->disposition) && $mail_part->filename)) {
+                 $mail_part->headers['content-id'] || $mail_part->filename) {
 
           // skip apple resource forks
           if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile')
