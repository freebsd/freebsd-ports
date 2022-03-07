--- lib/BinaryAttribute.php.orig	2021-12-12 02:35:51 UTC
+++ lib/BinaryAttribute.php
@@ -12,7 +12,7 @@
  * @package phpLDAPadmin
  * @subpackage Templates
  */
-class BinaryAttribute extends Attribute {
+class BinaryAttribute extends PLAAttribute {
 	protected $filepaths;
 	protected $filenames;
 
