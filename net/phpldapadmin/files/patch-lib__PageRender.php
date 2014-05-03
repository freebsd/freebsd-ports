--- ./lib/PageRender.php.orig	2012-10-01 07:54:14.000000000 +0100
+++ ./lib/PageRender.php	2014-05-03 07:57:44.744575309 +0100
@@ -287,7 +287,7 @@
 						break;
 
 					default:
-						$vals[$i] = password_hash($passwordvalue,$enc);
+						$vals[$i] = password_hash_custom($passwordvalue,$enc);
 				}
 
 				$vals = array_unique($vals);
@@ -957,7 +957,7 @@
 		if (trim($val))
 			$enc_type = get_enc_type($val);
 		else
-			$enc_type = $server->getValue('appearance','password_hash');
+			$enc_type = $server->getValue('appearance','password_hash_custom');
 
 		$obfuscate_password = obfuscate_password_display($enc_type);
 
@@ -982,7 +982,7 @@
 		if (trim($val))
 			$enc_type = get_enc_type($val);
 		else
-			$enc_type = $server->getValue('appearance','password_hash');
+			$enc_type = $server->getValue('appearance','password_hash_custom');
 
 		echo '<table cellspacing="0" cellpadding="0"><tr><td valign="top">';
 
