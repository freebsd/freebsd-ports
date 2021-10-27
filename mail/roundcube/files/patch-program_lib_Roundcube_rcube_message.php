--- program/lib/Roundcube/rcube_message.php.orig	2021-10-19 08:32:55.709205000 +0200
+++ program/lib/Roundcube/rcube_message.php	2021-10-19 08:34:30.613574000 +0200
@@ -910,8 +910,7 @@
                 else if (
                     preg_match('/^(inline|attach)/', $mail_part->disposition)
                     || $mail_part->headers['content-id']
-                    || ($mail_part->filename &&
-                        (empty($mail_part->disposition) || preg_match('/^[a-z0-9!#$&.+^_-]+$/i', $mail_part->disposition)))
+                    || $mail_part->filename
                 ) {
                     // skip apple resource forks
                     if ($message_ctype_secondary == 'appledouble' && $secondary_type == 'applefile') {
