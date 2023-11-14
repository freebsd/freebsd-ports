--- lib/LDAPEngine.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/LDAPEngine.class.php
@@ -93,7 +93,7 @@ class LDAPEngine {
 	/**
 	* LDAPEngine constructor to initialize object
 	*/
-	function LDAPEngine() {
+	function __construct() {
 		global $conf;
 
 		$this->serverType = strtolower($conf['auth']['serverType']);
@@ -283,6 +283,7 @@ class LDAPEngine {
      	*/
     	function searchUserDN($searchFilter) {
 
+		$dn = "";
 		switch ($this->serverType) {
 			case "ldap":
 				if ( $this->searchUser != '' ) {
