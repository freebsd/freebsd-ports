--- program/lib/Roundcube/rcube_message.php.orig	2010-11-26 13:41:16.000000000 +0100
+++ program/lib/Roundcube/rcube_message.php	2010-12-13 17:20:59.000000000 +0100
@@ -452,9 +452,7 @@
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
