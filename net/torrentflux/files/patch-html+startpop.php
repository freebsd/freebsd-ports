--- html/startpop.php.orig	Mon Oct 10 16:41:17 2005
+++ html/startpop.php	Mon Oct 10 16:42:20 2005
@@ -138,7 +138,7 @@
 
 function isNumber(sText)
 {
-	var ValidChars = "0123456789.";
+	var ValidChars = "0123456789.-";
 	var IsNumber = true;
 	var Char;
 
@@ -168,7 +168,7 @@
 		<table width="100%" cellpadding="3" cellspacing="0" border="0">
 		<tr>
 			<td align="right">Max Upload Rate:</td>
-			<td><input type="Text" name="maxRate" maxlength="4" size="4" value="<?php echo $cfg["max_upload_rate"]; ?>"> kB/s</td>
+			<td><input type="Text" name="maxRate" maxlength="4" size="4" value="<?php echo $cfg["max_upload_rate"]; ?>"> kB/s<font class="tiny"> (-1 = auto)</font></td>
 			<td align="right">Max # Uploads:</td>
 			<td><input type="Text" name="maxUploads" maxlength="2" size="2" value="<?php echo $cfg["max_uploads"]; ?>"></td>
 		</tr>
