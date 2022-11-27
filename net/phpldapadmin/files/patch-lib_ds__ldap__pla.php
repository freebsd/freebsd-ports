--- lib/ds_ldap_pla.php.orig	2021-12-12 02:35:51 UTC
+++ lib/ds_ldap_pla.php
@@ -248,7 +248,7 @@ class ldap_pla extends ldap {
 		# Next, compare strictly by name first
 		else
 			foreach ($_SESSION[APPCONFIG]->getValue('appearance','multi_line_attributes') as $multi_line_attr_name)
-				if (strcasecmp($multi_line_attr_name,$attr_name) == 0) {
+				if (strcasecmp((string) $multi_line_attr_name,(string) $attr_name) == 0) {
 					$return = true;
 					break;
 				}
@@ -285,8 +285,8 @@ class ldap_pla extends ldap {
 	 * @return boolean
 	 */
 	private function isAttrTest($attr,$attrs,$except_dn) {
-		$attr = trim($attr);
-		if (! trim($attr) || ! count($attrs))
+		$attr = trim((string) $attr);
+		if (! trim((string) $attr) || ! count($attrs))
 			return false;
 
 		# Is the user excluded?
@@ -294,7 +294,7 @@ class ldap_pla extends ldap {
 			return false;
 
 		foreach ($attrs as $attr_name)
-			if (strcasecmp($attr,trim($attr_name)) == 0)
+			if (strcasecmp((string) $attr,trim((string) (string) $attr_name)) == 0)
 				return true;
 
 		return false;
@@ -674,7 +674,7 @@ class ldap_pla extends ldap {
 		if ($this->getValue('appearance', 'show_authz') && function_exists('ldap_exop_whoami')) {
 			$result = @ldap_exop_whoami($this->connect($method));
 			if ($result) // strip any dn: or u: prefix
-				$result = preg_replace('/^(u|dn):/i', '', $result);
+				$result = preg_replace('/^(u|dn):/i', '',is_null( $result)? "": $result);
 			else // fall back to login on error
 				$result = $this->getLogin($method);
 			return $result;
