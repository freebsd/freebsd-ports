--- ./lib/ds_ldap.php.orig	2012-10-01 07:54:14.000000000 +0100
+++ ./lib/ds_ldap.php	2014-05-03 07:57:44.746572911 +0100
@@ -1116,13 +1116,24 @@
 
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
