--- html/dir.php.orig	Tue Oct  4 01:39:38 2005
+++ html/dir.php	Tue Oct  4 01:51:36 2005
@@ -104,15 +104,26 @@
 		
 		if (file_exists($path))
 		{
+			$fileSize = exec("stat -Lnqf %z ".escapeshellarg($path));
+
+			AuditAction($cfg["constants"]["fm_download"], $down."<br>Size:".$fileSize);
+
 			header("Content-type: application/octet-stream\n");
 			header("Content-disposition: attachment; filename=\"".$file."\"\n");
 			header("Content-transfer-encoding: binary\n");
-			header("Content-length: " . filesize($path) . "\n");
+			header("Content-length: " . $fileSize . "\n");
+
+			while (ob_get_level() > 0) {
+				ob_end_flush();
+			}
 			
 			$fp = fopen($path, "r");
-			fpassthru($fp);
+			while(!feof($fp)) {
+				set_time_limit(60);
+				print(fread($fp, 1024*8));
+				ob_flush();
+			}
 		
-			AuditAction($cfg["constants"]["fm_download"], $down);
 			exit();
 		}
 		else
@@ -283,8 +294,19 @@
 			if (@is_dir($dirName.$entry))
 			{
 				echo "<tr bgcolor=\"".$bg."\"><td><a href=\"dir.php?dir=".urlencode($dir.$entry)."\"><img src=\"images/folder2.gif\" width=\"16\" height=\"16\" title=\"".$entry."\" border=\"0\" align=\"absmiddle\">".$entry."</a></td>";
-				echo "<td>&nbsp;</td>";
-				echo "<td>&nbsp;</td>";
+				if ($cfg["show_directory_size"])
+				{
+					$timeStamp = filectime($dirName.$entry);
+					$arFileSize = explode("\t", exec("du -sk ".escapeshellarg($dirName.$entry)));
+					$fileSize = $arFileSize[0];
+					echo "<td align=\"right\">".$fileSize." KB</td>";
+					echo "<td>".date("m-d-Y g:i a", $timeStamp)."</td>";
+				} 
+				else
+				{ 
+					echo "<td>&nbsp;</td>";
+					echo "<td>&nbsp;</td>";
+				} 
 				echo "<td align=\"right\">";
 				
 				if ($cfg["enable_file_download"])
@@ -340,9 +362,9 @@
 			}
 			else
 			{
-				$arStat = @lstat($dirName.$entry);
-				$timeStamp = $arStat[10];
-				$fileSize = number_format(($arStat[7])/1024);
+				$timeStamp = filectime($dirName.$entry);
+				$arFileSize = explode("\t", exec("du -sk ".escapeshellarg($dirName.$entry)));
+				$fileSize = $arFileSize[0];
 				// Code added by Remko Jantzen to assign an icon per file-type. But when not
 				// available all stays the same.
 				$image="images/time.gif";
@@ -423,7 +445,7 @@
 	if (!is_dir($cfg["path"].$cfg["user"]))
 	{
 		//Then create it
-		mkdir($cfg["path"].$cfg["user"], 0777);
+		mkdir($cfg["path"].$cfg["user"], 0755);
 	}
 }
 
