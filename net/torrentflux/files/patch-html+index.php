--- html/index.php.orig	Mon Oct 10 00:08:03 2005
+++ html/index.php	Mon Oct 10 00:08:54 2005
@@ -33,11 +33,11 @@
 {
 	include_once("AliasFile.php");
 	$command = "";
-	If (empty($rate))
+	If (!isset($rate))
 	{
 		$rate = $cfg["max_upload_rate"];
 	}
-	if (empty($drate)) {
+	if (!isset($drate)) {
 		$drate = $cfg["max_download_rate"];
 	}
 	if (empty($superseeder)) {
@@ -97,6 +97,7 @@
 	//AuditAction($cfg["constants"]["start_torrent"], $torrent);
 	AuditAction($cfg["constants"]["start_torrent"], $torrent."<br>Die:".$runtime.", Sharekill:".$sharekill.", MaxUploads:".$maxuploads.", DownRate:".$drate.", UploadRate:".$rate.", Ports:".$minport."-".$maxport.", SuperSeed:".$superseeder);
 
+	sleep(2); // wait 2 seconds
 	header("location: index.php");
 }
 
@@ -192,7 +193,7 @@
 			{
 				if(move_uploaded_file($_FILES['upload_file']['tmp_name'], $cfg["torrent_file_path"].$file_name))
 				{
-					chmod($cfg["torrent_file_path"].$file_name, 0644);
+					chmod($cfg["torrent_file_path"].$file_name, 0640);
 				
 					AuditAction($cfg["constants"]["file_upload"], $file_name);
 				
@@ -221,6 +222,21 @@
 	}
 }  // End File Upload
 
+// adopt abandoned torrents
+if(isset($takefile))
+{
+	if (("n/a" == getOwner($delfile)) && IsAdmin())
+	{
+		AuditAction($cfg["constants"]["file_upload"], $takefile);
+
+		header("location: index.php");
+	}
+	else
+	{
+		AuditAction($cfg["constants"]["error"], $cfg["user"]." attempted to take ".$takefile);
+	}
+}
+
 
 // if a file was set to be deleted then delete it
 if(isset($delfile))
@@ -565,10 +581,10 @@
 	Total Download: <strong><?php echo number_format($cfg["total_download"], 2); ?></strong> kB/s<br>
 	Free Space: <strong><?php echo formatFreeSpace($cfg["free_space"]) ?></strong>
 <?php 
-	if ($cfg["show_server_load"] && is_file($cfg["loadavg_path"]))
+	if ($cfg["show_server_load"])
 	{
-		$loadavg_array = explode(" ", exec("cat ".$cfg["loadavg_path"]));
-		$loadavg = $loadavg_array[2];
+		$loadavg_array = explode(" ", exec("sysctl -n vm.loadavg"));
+		$loadavg = $loadavg_array[3];
 		echo "<br>Server Load: <strong>".$loadavg."</strong>";
 	}
 ?>
