--- share/pnp/application/models/auth.php.orig	2017-08-21 15:52:37 UTC
+++ share/pnp/application/models/auth.php
@@ -116,11 +116,7 @@ class Auth_Model extends System_Model {
             $result = $this->queryLivestatus($query);
         }
 
-        if(sizeof($result) > 0){
-            return TRUE;
-        }else{
-            return FALSE;
-        }
+        return (!empty($result));
     }
 
 
