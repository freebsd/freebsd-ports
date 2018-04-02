--- lib/PageRender.php.orig	2012-10-01 06:54:14 UTC
+++ lib/PageRender.php
@@ -287,7 +287,7 @@ class PageRender extends Visitor {
 						break;
 
 					default:
-						$vals[$i] = password_hash($passwordvalue,$enc);
+						$vals[$i] = password_hash_custom($passwordvalue,$enc);
 				}
 
 				$vals = array_unique($vals);
@@ -957,7 +957,7 @@ class PageRender extends Visitor {
 		if (trim($val))
 			$enc_type = get_enc_type($val);
 		else
-			$enc_type = $server->getValue('appearance','password_hash');
+			$enc_type = $server->getValue('appearance','password_hash_custom');
 
 		$obfuscate_password = obfuscate_password_display($enc_type);
 
@@ -982,7 +982,7 @@ class PageRender extends Visitor {
 		if (trim($val))
 			$enc_type = get_enc_type($val);
 		else
-			$enc_type = $server->getValue('appearance','password_hash');
+			$enc_type = $server->getValue('appearance','password_hash_custom');
 
 		echo '<table cellspacing="0" cellpadding="0"><tr><td valign="top">';
 
