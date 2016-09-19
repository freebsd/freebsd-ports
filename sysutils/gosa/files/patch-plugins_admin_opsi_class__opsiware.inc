--- plugins/admin/opsi/class_opsiware.inc.orig	2008-09-05 08:38:26 UTC
+++ plugins/admin/opsi/class_opsiware.inc
@@ -1,16 +1,5 @@
 <?php
 
-class opsiSoftware extends opsiWare
-{
-  protected $type = 0;
-}
-
-class opsiHardware extends opsiWare
-{
-  protected $type = 1;
-}
-
-
 class opsiWare extends plugin
 {
   private $opsi;
@@ -57,5 +46,17 @@ class opsiWare extends plugin
     return($smarty->fetch(get_template_path("opsiware.tpl",TRUE,dirname(__FILE__))));
   }
 }
+
+
+class opsiSoftware extends opsiWare
+{
+  protected $type = 0;
+}
+
+class opsiHardware extends opsiWare
+{
+  protected $type = 1;
+}
+
 // vim:tabstop=2:expandtab:shiftwidth=2:filetype=php:syntax:ruler:
 ?>
