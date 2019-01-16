--- share/pnp/application/controllers/ajax.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/controllers/ajax.php
@@ -59,7 +59,7 @@ class Ajax_Controller extends System_Controller  {
 
         if($action == "list"){
             $basket = $this->session->get("basket");
-            if(is_array($basket) && sizeof($basket) > 0){
+            if(is_array($basket) && (!empty($basket))){
                 foreach($basket as $item){
                 printf("<li class=\"ui-state-default %s\" id=\"%s\"><a title=\"%s\" id=\"%s\"><img width=12px height=12px src=\"%smedia/images/remove.png\"></a>%s</li>\n",
                         "basket_action_remove",
@@ -135,7 +135,7 @@ class Ajax_Controller extends System_Controller  {
             echo "Action $action not known";
         }
         $basket = $this->session->get("basket");
-        if(is_array($basket) && sizeof($basket) == 0){
+        if(is_array($basket) && empty($basket)){
             echo Kohana::lang('common.basket-empty');
         }else{
             echo "<div align=\"center\" class=\"p2\">\n";
