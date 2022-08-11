--- program/lib/Roundcube/rcube_message.php.orig	2022-06-26 20:26:58 UTC
+++ program/lib/Roundcube/rcube_message.php
@@ -914,8 +914,7 @@ class rcube_message
                 else if (
                     preg_match('/^(inline|attach)/', $mail_part->disposition)
                     || !empty($mail_part->headers['content-id'])
-                    || ($mail_part->filename &&
-                        (empty($mail_part->disposition) || preg_match('/^[a-z0-9!#$&.+^_-]+$/i', $mail_part->disposition)))
+                    || $mail_part->filename
                 ) {
                     // skip apple resource forks
                     if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile') {
