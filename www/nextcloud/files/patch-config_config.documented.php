--- config/config.documented.php.orig	2020-05-26 10:01:24 UTC
+++ config/config.documented.php
@@ -927,6 +927,11 @@ $CONFIG = [
 		'url' => '/apps',
 		'writable' => true,
 	],
+	[
+		'path'=> '/usr/local/www/nextcloud/apps-pkg',
+		'url' => '/apps-pkg',
+		'writable' => false,
+	],
 ],
 
 /**
