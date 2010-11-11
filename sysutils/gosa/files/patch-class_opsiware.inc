--- plugins/admin/opsi/class_opsiware.inc.orig	2008-09-05 12:38:26.000000000 +0400
+++ plugins/admin/opsi/class_opsiware.inc	2010-05-15 21:53:22.000000000 +0400
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
@@ -57,5 +46,17 @@
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
