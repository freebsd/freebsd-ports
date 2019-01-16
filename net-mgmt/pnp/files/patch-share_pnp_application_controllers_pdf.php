--- share/pnp/application/controllers/pdf.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/controllers/pdf.php
@@ -202,7 +202,7 @@ class Pdf_Controller extends System_Controller  {
         }
         $this->data->getTimeRange($this->start,$this->end,$this->view);
         $basket = $this->session->get("basket");
-        if(is_array($basket) && sizeof($basket) > 0){
+        if(is_array($basket) && (!empty($basket))){
              $this->data->buildBasketStruct($basket,$this->view);
         }
         //echo Kohana::debug($this->data->STRUCT);
