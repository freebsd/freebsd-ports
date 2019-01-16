--- share/pnp/application/controllers/image.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/controllers/image.php
@@ -47,7 +47,7 @@ class Image_Controller extends System_Controller  {
                 $this->rrdtool->streamImage("ERROR: NOT_AUTHORIZED"); 
 
             #print Kohana::debug($this->data->STRUCT);
-            if(sizeof($this->data->STRUCT) > 0){
+            if(!empty($this->data->STRUCT)){
                 $image = $this->rrdtool->doImage($this->data->STRUCT[0]['RRD_CALL']);
             }else{
                 $image = FALSE;
