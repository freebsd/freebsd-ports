--- program/lib/Roundcube/rcube_message.php.orig	2017-06-26 20:56:48.000000000 +0200
+++ program/lib/Roundcube/rcube_message.php	2017-06-30 10:20:36.889381000 +0200
@@ -830,9 +830,7 @@ class rcube_message
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
