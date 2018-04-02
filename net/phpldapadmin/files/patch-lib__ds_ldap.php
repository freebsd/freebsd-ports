--- lib/ds_ldap.php.orig	2012-10-01 06:54:14 UTC
+++ lib/ds_ldap.php
@@ -1116,13 +1116,24 @@ class ldap extends DS {
 
 		if (is_array($dn)) {
 			$a = array();
-			foreach ($dn as $key => $rdn)
-				$a[$key] = preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$rdn);
+			foreach ($dn as $key => $rdn) {
+				$a[$key] = preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+					function ($m) {
+						return ''.chr(hexdec('\\1')).'';
+					},
+					$rdn
+					);
+			}
 
 			return $a;
 
 		} else
-			return preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$dn);
+			 return preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+				function ($m) {
+					return ''.chr(hexdec('\\1')).'';
+				},
+				$dn
+			);
 	}
 
 	public function getRootDSE($method=null) {
