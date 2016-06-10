--- program/lib/Roundcube/rcube_message.php.orig	2016-05-22 11:06:47 UTC
+++ program/lib/Roundcube/rcube_message.php
@@ -766,9 +766,7 @@ class rcube_message
                 }
                 // part is a file/attachment
                 else if (preg_match('/^(inline|attach)/', $mail_part->disposition) ||
-                    $mail_part->headers['content-id'] ||
-                    ($mail_part->filename &&
-                        (empty($mail_part->disposition) || preg_match('/^[a-z0-9!#$&.+^_-]+$/i', $mail_part->disposition)))
+                    $mail_part->headers['content-id'] || $mail_part->filename
                 ) {
                     // skip apple resource forks
                     if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile')
