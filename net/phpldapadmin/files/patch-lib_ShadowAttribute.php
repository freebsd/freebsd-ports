--- lib/ShadowAttribute.php.orig	2021-12-12 02:35:51 UTC
+++ lib/ShadowAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class ShadowAttribute extends Attribute {
+class ShadowAttribute extends PLAAttribute {
 	public $shadow_before_today_attrs = array('shadowLastChange','shadowMin');
 	public $shadow_after_today_attrs = array('shadowMax','shadowExpire','shadowWarning','shadowInactive');
 }
