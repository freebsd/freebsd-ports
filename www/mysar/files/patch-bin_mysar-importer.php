--- bin/mysar-importer.php.orig	Wed Jan 11 15:03:03 2006
+++ bin/mysar-importer.php	Wed Jan 11 15:03:26 2006
@@ -123,7 +123,7 @@
 	$dbRecord['resultCode']=$record[3];
 	$dbRecord['bytes']=$record[4];
 	$dbRecord['url']=addslashes($record[6]);
-	$dbRecord['authuser']=$record[7];
+	$dbRecord['authuser']=substr($record[7],0,20);
 
 	$resultCodeArray=explode('/',$dbRecord['resultCode']);
 	if(in_array($resultCodeArray[0],$inCacheCodes)) {
