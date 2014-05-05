--- ./lib/functions.php.orig	2012-10-01 07:54:14.000000000 +0100
+++ ./lib/functions.php	2014-05-03 07:57:44.751570981 +0100
@@ -2127,7 +2127,7 @@
  *        crypt, ext_des, md5crypt, blowfish, md5, sha, smd5, ssha, sha512, or clear.
  * @return string The hashed password.
  */
-function password_hash($password_clear,$enc_type) {
+function password_hash_custom($password_clear,$enc_type) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -2318,7 +2318,7 @@
 
 		# SHA crypted passwords
 		case 'sha':
-			if (strcasecmp(password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
+			if (strcasecmp(password_hash_custom($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2327,7 +2327,7 @@
 
 		# MD5 crypted passwords
 		case 'md5':
-			if( strcasecmp(password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
+			if( strcasecmp(password_hash_custom($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2392,7 +2392,7 @@
 
 		# SHA512 crypted passwords
 		case 'sha512':
-			if (strcasecmp(password_hash($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
+			if (strcasecmp(password_hash_custom($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2564,13 +2564,24 @@
 	if (is_array($dn)) {
 		$a = array();
 
-		foreach ($dn as $key => $rdn)
-			$a[$key] = preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$rdn);
+		foreach ($dn as $key => $rdn) {
+			$a[$key] = preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+				function ($m) {
+					return ''.chr(hexdec('\\1')).'';
+				},
+				$rdn
+			);
+		}
 
 		return $a;
 
 	} else {
-		return preg_replace('/\\\([0-9A-Fa-f]{2})/e',"''.chr(hexdec('\\1')).''",$dn);
+		 return  preg_replace_callback('/\\\([0-9A-Fa-f]{2})/',
+			 function ($m) {
+				return ''.chr(hexdec('\\1')).'';
+			},
+			$dn
+		);
 	}
 }
 
