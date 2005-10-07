--- action.php.orig	Thu Jun 30 07:34:45 2005
+++ action.php	Fri Oct  7 21:01:29 2005
@@ -77,7 +77,8 @@
             if ($conf->display_img_attach && (eregi('image', $tmp['mime']) && ($tmp['number'] != '')))
             {
                 // if it's an image, display it
-                $img_type = array_pop(explode('/', $tmp['mime']));
+                $exploded = explode('/', $tmp['mime']);
+                $img_type = array_pop($exploded);
                 if (eregi('JPEG', $img_type) || eregi('JPG', $img_type) || eregi('GIF', $img_type) || eregi ('PNG', $img_type))
                 {
                     echo '<hr />';
@@ -156,10 +157,12 @@
             if (isset($user_prefs->reply_leadin) && ($user_prefs->reply_leadin != ''))
             {
                 $parsed_leadin = NOCCUserPrefs::parseLeadin($user_prefs->reply_leadin, $content);
-                $mail_body = mailquote(strip_tags($content['body'], ''), $parsed_leadin, '');
+                $stripped_content = strip_tags($content['body'], '');
+                $mail_body = mailquote($stripped_content, $parsed_leadin, '');
             }
             else
-                $mail_body = mailquote(strip_tags($content['body'], ''), $content['from'], $html_wrote);
+                $stripped_content = strip_tags($content['body'], '');
+                $mail_body = mailquote($stripped_content, $content['from'], $html_wrote);
         }
 
         // Add signature
@@ -204,8 +207,10 @@
         // Set body
         if(isset($user_prefs->outlook_quoting) && $user_prefs->outlook_quoting)
             $mail_body = $original_msg . "\n" . $html_from . ': ' . $content['from'] . "\n" . $html_to . ': ' . $content['to'] . "\n" . $html_sent.': ' . $content['complete_date'] . "\n" . $html_subject . ': '. $content['subject'] . "\n\n" . strip_tags2($content['body'], '');
-        else
-            $mail_body = mailquote(strip_tags2($content['body'], ''), $content['from'], $html_wrote);
+        else {
+            $stripped_content = strip_tags2($content['body'], '');
+            $mail_body = mailquote($stripped_content, $content['from'], $html_wrote);
+        }
 
         // Add signature
         add_signature($mail_body);
