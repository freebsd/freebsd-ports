--- program/include/rcube_message.php.orig	2010-08-06 15:22:20.000000000 +0200
+++ program/include/rcube_message.php	2010-08-24 12:42:33.000000000 +0200
@@ -427,7 +427,7 @@
                 }
                 // part is a file/attachment
                 else if (preg_match('/^(inline|attach)/', $mail_part->disposition) ||
-                    $mail_part->headers['content-id'] || (empty($mail_part->disposition) && $mail_part->filename)
+                    $mail_part->headers['content-id'] || $mail_part->filename
                 ) {
                     // skip apple resource forks
                     if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile')
