--- icq.php.orig	Mon Oct 15 23:12:21 2001
+++ icq.php	Mon Dec 31 00:37:35 2001
@@ -17,10 +17,10 @@
 
 $uin = Horde::getFormData('uin');
 $results="";
+$email_next=false;
 if (!empty($uin)) {
-	$fd = fopen("http://wwp.icq.com/$uin", 'r');
+	$fd = fopen("http://web.icq.com/wwp?Uin=" . $uin, 'r');
 	while ($buffer = fgetss($fd, 4096)) {
-		
 		if (ereg('Handle/Nickname:', $buffer)) {
 		//	echo ereg_replace('Handle/Nickname:', 'NickName: ', $buffer);
 		//	echo "<br>";
@@ -34,6 +34,20 @@
 			$results .= ereg_replace('E-Mail', 'Email: ', $buffer);
 			$results .="<br>";
 		}
+		
+		if (ereg('Hello my name is', $buffer)) {
+			$results .= ereg_replace('Hello my name is', 'Name:', $buffer);
+			$results .="<br>";
+		}
+		
+		if ($email_next) {
+			$results .= 'Email: ' . $buffer;
+			$email_next = false;
+		}
+		if (ereg('Send me an Email message', $buffer)) {
+			$email_next = true;
+		}
+
 	}
 	fclose($fd);
 	
