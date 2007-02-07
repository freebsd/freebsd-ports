--- html/inc/libmisc.php.orig	Mon Feb  5 17:51:32 2007
+++ html/inc/libmisc.php	Mon Feb  5 17:51:32 2007
@@ -16,8 +16,8 @@
 // Read configuration
 function ReadConf($group) {
 
-	if (file_exists('/etc/nedi.conf')) {
-		$conf = file('/etc/nedi.conf');
+	if (file_exists('/usr/local/etc/nedi.conf')) {
+		$conf = file('/usr/local/etc/nedi.conf');
 	}elseif (file_exists('/var/nedi/nedi.conf')) {
 		$conf = file('/var/nedi/nedi.conf');
 	}else{
