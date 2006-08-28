--- implementation/database/upgrade/2.1.x/transfer_images.php.orig	Mon Aug 21 14:15:42 2006
+++ implementation/database/upgrade/2.1.x/transfer_images.php	Mon Aug 21 14:17:36 2006
@@ -120,7 +120,7 @@
 //	$transferQuery = "INSERT INTO ImagesDup (Description, Photographer, Place, Date, ContentType, Location, URL, NrArticle, Number, Image) SELECT Description, Photographer, Place, Date, ContentType, 'local', '', NrArticle, Number, Image FROM Images";
 //	mysql_query($transferQuery);
 	
-	$thumbnailCommand = 'convert -sample 64x64';
+	$thumbnailCommand = 'gm convert -sample 64x64';
 	$queryStr = "SELECT Id, Image FROM ImagesDup";
 	$query = mysql_query($queryStr);
 	//mkdir($p_destDir, 0755);
