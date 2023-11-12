--- lib/LDAPEngine.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/LDAPEngine.class.php
@@ -283,6 +283,7 @@ class LDAPEngine {
      	*/
     	function searchUserDN($searchFilter) {
 
+		$dn = "";
 		switch ($this->serverType) {
 			case "ldap":
 				if ( $this->searchUser != '' ) {
