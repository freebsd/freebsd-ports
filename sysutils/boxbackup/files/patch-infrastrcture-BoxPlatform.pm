--- infrastructure/BoxPlatform.pm.orig	Sat Jan  8 13:27:12 2005
+++ infrastructure/BoxPlatform.pm	Sat Jan  8 13:27:33 2005
@@ -78,7 +78,7 @@
 	close VERSION;
 	
 	# where to put the files
-	$install_into_dir = '/usr/local/bin';
+	$install_into_dir = '%%PREFIX%%/bin';
 	
 	# if it's Darwin,
 	if($build_os eq 'Darwin')
