--- plugins/message_details/message_details_bottom.php.orig	2012-11-16 16:16:25.000000000 -0500
+++ plugins/message_details/message_details_bottom.php	2012-11-16 16:16:49.000000000 -0500
@@ -85,7 +85,7 @@
 $messageheaderstart=false;
 $boundaries = array();
 $entities = array();
-session_unregister("entities");
+sqsession_unregister("entities");
 $pre = '<b>';
 $end = '</b>';
 $entStr = '';
