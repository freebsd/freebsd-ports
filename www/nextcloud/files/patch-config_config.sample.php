--- config/config.sample.php.orig	2018-03-13 18:47:31 UTC
+++ config/config.sample.php
@@ -818,6 +818,11 @@ $CONFIG = array(
 		'url' => '/apps',
 		'writable' => true,
 	),
+	array(
+		'path'=> '/var/www/nextcloud/apps-pkg',
+		'url' => '/var/www/apps-pkg',
+		'writable' => false,
+	),
 ),
 
 /**
