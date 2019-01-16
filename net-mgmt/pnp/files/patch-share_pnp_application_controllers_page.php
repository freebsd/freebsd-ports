--- share/pnp/application/controllers/page.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/controllers/page.php
@@ -58,7 +58,7 @@ class Page_Controller extends System_Controller  {
 
     public function basket(){
         $basket = $this->session->get("basket");
-        if(is_array($basket) && sizeof($basket) > 0){
+        if(is_array($basket) && (!empty($basket))){
             $this->data->buildBasketStruct($basket,$this->view);
             $this->template->page->basket_box         = $this->add_view('basket_box');
             $this->template->page->header->title      = Kohana::lang('common.page-basket');
