--- lib/ds_ldap_pla.php.orig	2012-10-01 06:54:14 UTC
+++ lib/ds_ldap_pla.php
@@ -16,7 +16,7 @@ class ldap_pla extends ldap {
 	function __construct($index) {
 		parent::__construct($index);
 
-		$this->default->appearance['password_hash'] = array(
+		$this->default->appearance['password_hash_custom'] = array(
 			'desc'=>'Default HASH to use for passwords',
 			'default'=>'md5');
 
