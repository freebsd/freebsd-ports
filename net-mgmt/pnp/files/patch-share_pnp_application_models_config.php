--- share/pnp/application/models/config.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/models/config.php
@@ -68,7 +68,7 @@ class Config_Model extends System_Model
                 $views = array();
                 include ($config_file);
                 $array_b = $views;
-                if(sizeof($views) == 0 ){
+                if(empty($views)){
                     $views = $array_a;
                 }
             }
