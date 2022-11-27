--- htdocs/purge_cache.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/purge_cache.php
@@ -16,7 +16,7 @@ $purge_session_keys = array('app_initialized','backtra
 $size = 0;
 foreach ($purge_session_keys as $key)
 	if (isset($_SESSION[$key])) {
-		$size += strlen(serialize($_SESSION[$key]));
+		$size += strlen((string) serialize($_SESSION[$key]));
 		unset($_SESSION[$key]);
 	}
 
