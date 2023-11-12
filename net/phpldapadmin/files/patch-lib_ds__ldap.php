--- lib/ds_ldap.php.orig	2023-04-01 13:46:16 UTC
+++ lib/ds_ldap.php
@@ -991,7 +991,7 @@ class ldap extends DS {
 		$return = $dn;
 
 		foreach ($this->getBaseDN() as $base) {
-			if (preg_match("/${base}$/i",$dn)) {
+			if (preg_match("/{$base}$/i",$dn)) {
 				$return = $base;
 				break;
 			}
