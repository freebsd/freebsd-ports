--- lib/Quarantine.lib.php.orig	2007-06-14 19:00:15 UTC
+++ lib/Quarantine.lib.php
@@ -65,7 +65,7 @@ function releaseMessages($emailaddresses
 	foreach ($mail_id_array as $mail_id_recip) {
 
 		// Get mail_id and recipient email address
-		$temp = preg_split('/_/', $mail_id_recip, 2);
+		$temp = preg_split('/__/', $mail_id_recip, 2);
 		$mail_id = $temp[0];
 		$recip_email = $temp[1];
 
@@ -258,7 +258,7 @@ function updateMessages($flag, $content_
 		foreach ($mail_id_array as $mail_id_recip) {
 		
 			// Get mail_id and recipient email address
-			$temp = preg_split('/_/', $mail_id_recip, 2);
+			$temp = preg_split('/__/', $mail_id_recip, 2);
 			$mail_id = $temp[0];
 			$recip_email = $temp[1];
 
