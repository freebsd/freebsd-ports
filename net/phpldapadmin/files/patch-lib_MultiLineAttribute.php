--- lib/MultiLineAttribute.php.orig	2021-12-12 02:35:51 UTC
+++ lib/MultiLineAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class MultiLineAttribute extends Attribute {
+class MultiLineAttribute extends PLAAttribute {
 	protected $rows = 0;
 	protected $cols = 0;
 
