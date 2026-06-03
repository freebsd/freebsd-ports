--- config/config.documented.php.orig	2026-02-17 17:36:43 UTC
+++ config/config.documented.php
@@ -1408,6 +1408,11 @@ $CONFIG = [
 			'url' => '/apps',
 			'writable' => true,
 		],
+		[
+			'path' => '/var/www/nextcloud/apps-pkg',
+			'url' => '/apps-pkg',
+			'writable' => false,
+		],
 	],
 
 	/**
