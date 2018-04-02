--- lib/functions.php.orig	2012-10-01 06:54:14 UTC
+++ lib/functions.php
@@ -745,6 +745,7 @@ function blowfish_encrypt($data,$secret=
 	if (! trim($secret))
 		return $data;
 
+/*
 	if (function_exists('mcrypt_module_open') && ! empty($data)) {
 		$td = mcrypt_module_open(MCRYPT_BLOWFISH,'',MCRYPT_MODE_ECB,'');
 		$iv = mcrypt_create_iv(mcrypt_enc_get_iv_size($td),MCRYPT_DEV_URANDOM);
@@ -754,6 +755,7 @@ function blowfish_encrypt($data,$secret=
 
 		return $encrypted_data;
 	}
+*/
 
 	if (file_exists(LIBDIR.'blowfish.php'))
 		require_once LIBDIR.'blowfish.php';
@@ -801,6 +803,7 @@ function blowfish_decrypt($encdata,$secr
 	if (! trim($secret))
 		return $encdata;
 
+/*
 	if (function_exists('mcrypt_module_open') && ! empty($encdata)) {
 		$td = mcrypt_module_open(MCRYPT_BLOWFISH,'',MCRYPT_MODE_ECB,'');
 		$iv = mcrypt_create_iv(mcrypt_enc_get_iv_size($td),MCRYPT_DEV_URANDOM);
@@ -810,6 +813,7 @@ function blowfish_decrypt($encdata,$secr
 
 		return $decrypted_data;
 	}
+*/
 
 	if (file_exists(LIBDIR.'blowfish.php'))
 		require_once LIBDIR.'blowfish.php';
@@ -2127,7 +2131,7 @@ function password_types() {
  *        crypt, ext_des, md5crypt, blowfish, md5, sha, smd5, ssha, sha512, or clear.
  * @return string The hashed password.
  */
-function password_hash($password_clear,$enc_type) {
+function password_hash_custom($password_clear,$enc_type) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
@@ -2318,7 +2322,7 @@ function password_check($cryptedpassword
 
 		# SHA crypted passwords
 		case 'sha':
-			if (strcasecmp(password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
+			if (strcasecmp(password_hash_custom($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2327,7 +2331,7 @@ function password_check($cryptedpassword
 
 		# MD5 crypted passwords
 		case 'md5':
-			if( strcasecmp(password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
+			if( strcasecmp(password_hash_custom($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2392,7 +2396,7 @@ function password_check($cryptedpassword
 
 		# SHA512 crypted passwords
 		case 'sha512':
-			if (strcasecmp(password_hash($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
+			if (strcasecmp(password_hash_custom($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2564,13 +2568,24 @@ function dn_unescape($dn) {
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
 
