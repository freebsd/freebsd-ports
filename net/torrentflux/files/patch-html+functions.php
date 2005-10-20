--- html/functions.php.orig	Fri Oct  7 00:39:53 2005
+++ html/functions.php	Fri Oct  7 00:41:16 2005
@@ -49,9 +49,9 @@
 // avddelete()
 function avddelete($file)
 {
-	chmod($file,0777);
 	if (@is_dir($file))
 	{
+		chmod($file,0755);
 		$handle = @opendir($file);
 		while($filename = readdir($handle))
 		{
@@ -65,6 +65,7 @@
 	}
 	else
 	{
+		chmod($file,0644);
 		@unlink($file);
 	}
 }
@@ -872,7 +873,7 @@
 	global $cfg;
 	
 	echo "<div align=\"right\">";
-	echo "<a href=\"http://www.torrentflux.com\" target=\"_blank\"><font class=\"tinywhite\">TorrentFlux ".$cfg["version"]."</font></a>&nbsp;&nbsp;";
+	echo "<a href=\"http://www.torrentflux.com\" target=\"_blank\"><font class=\"tinywhite\">TorrentFlux %%PORTVERSION%%</font></a>&nbsp;&nbsp;";
 	echo "</div>";
 }
 
@@ -1028,7 +1029,7 @@
 	if (!is_dir($cfg["torrent_file_path"]))
 	{
 		//Then create it
-		mkdir($cfg["torrent_file_path"], 0777);
+		mkdir($cfg["torrent_file_path"], 0755);
 	}
 }
 
@@ -1152,7 +1153,7 @@
 // Remove bad characters that cause problems
 function cleanFileName($inName)
 {
-	$replaceItems = array("'", ",", "#", "%", "!", "+", ":", "/", "\\", "@", "$", "&", "?");
+	$replaceItems = array("'", ",", "#", "%", "!", "+", ":", "/", "\\", "@", "$", "&", "?", "\"");
     $cleanName = str_replace($replaceItems, "", $inName);
 
 	return $cleanName;
@@ -1264,7 +1265,7 @@
 	if (strpos($rtnValue, "d8:") === false)
 	{
 		// We don't have a Torrent File... it is something else
-		AuditAction($cfg["constants"]["error"], "BAD TORRENT for: ".$url."\n".$rtnValue);
+		AuditAction($cfg["constants"]["error"], "BAD TORRENT for: ".$url."<br>".htmlspecialchars(substr($rtnValue, 0, 512)));
 		$rtnValue = "";
 	}
 	return $rtnValue;
@@ -1564,7 +1565,7 @@
 			if($kill_id != "" && $af->percent_done >= 0 && $af->running == 1)
 			{
 				
-				$output .= "<a href=\"index.php?alias_file=".$alias."&kill=".$kill_id."&kill_torrent=".urlencode($entry)."\"><img src=\"images/kill.gif\" width=16 height=16 title=\""._STOPDOWNLOAD."\n"._USER.": ".$lastUser."\" border=0></a>";
+				$output .= "<a href=\"index.php?alias_file=".$alias."&kill=".$kill_id."&kill_torrent=".urlencode($entry)."\"><img src=\"images/kill.gif\" width=16 height=16 title=\""._STOPDOWNLOAD." ("._USER.": ".$lastUser.")\" border=0></a>";
 				$output .= "<img src=\"images/delete_off.gif\" width=16 height=16 border=0>";
 				
 			}
@@ -1572,7 +1573,8 @@
 			{
 				if($torrentowner == "n/a")
 				{
-					$output .= "<img src=\"images/run_off.gif\" width=16 height=16 border=0 title=\""._NOTOWNER."\">";
+					$takelink = $_SERVER['PHP_SELF']."?alias_file=".$alias."&takefile=".urlencode($entry);
+					$output .= "<a href=\"".$takelink."\"><img src=\"images/run_off.gif\" width=16 height=16 border=0 title=\""._NOTOWNER."\"></a>";
 				}
 				else
 				{
