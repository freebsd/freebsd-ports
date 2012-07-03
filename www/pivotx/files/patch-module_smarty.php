--- pivotx/modules/module_smarty.php.orig	2012-04-13 00:04:12.000000000 +0900
+++ pivotx/modules/module_smarty.php	2012-06-14 20:57:40.000000000 +0900
@@ -5439,7 +5439,7 @@
 /**
  * @see $smarty->register_resource
  */
-function dbGetTemplate($tpl_name, $tpl_source, &$smarty_obj) {
+function dbGetTemplate($tpl_name, &$tpl_source, &$smarty_obj) {
 
     if (isset($smarty_obj->custom_template[ $tpl_name ])) {
         $tpl_source = $smarty_obj->custom_template[ $tpl_name ];
