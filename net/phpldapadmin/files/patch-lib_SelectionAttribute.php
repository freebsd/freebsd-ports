--- lib/SelectionAttribute.php.orig	2021-12-12 02:35:51 UTC
+++ lib/SelectionAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class SelectionAttribute extends Attribute {
+class SelectionAttribute extends PLAAttribute {
 	protected $selection = array();
 	protected $multiple;
 	protected $default;
