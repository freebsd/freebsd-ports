--- share/pnp/application/views/basket_box.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/views/basket_box.php
@@ -6,7 +6,7 @@ echo "<div class=\"p2 ui-widget-header ui-corner-top\"
 echo Kohana::lang('common.basket-box-header')."</div>\n";
 echo "<div class=\"p4 ui-widget-content ui-corner-bottom\">\n";
 echo "<div id=\"basket_items\">\n";
-if(is_array($basket) && sizeof($basket) > 0 ){
+if(is_array($basket) && !empty($basket)){
 	foreach($basket as $key=>$item){
 		echo "<li class=\"ui-state-default basket_action_remove\" id=\"".
                      $item."\"><a title=\"".Kohana::lang('common.basket-remove', $item)."\"".
@@ -16,7 +16,7 @@ if(is_array($basket) && sizeof($basket) > 0 ){
                      pnp::shorten($item)."</li>\n";
 	}
 }
-if(is_array($basket) && sizeof($basket) > 0 ){
+if(is_array($basket) && !empty($basket)){
     echo "<div align=\"center\" class=\"p2\">\n";
     echo "<button id=\"basket-show\">".Kohana::lang('common.basket-show')."</button>\n";
     echo "<button id=\"basket-clear\">".Kohana::lang('common.basket-clear')."</button>\n";
