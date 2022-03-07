--- lib/AttributeFactory.php.orig	2021-12-12 02:35:51 UTC
+++ lib/AttributeFactory.php
@@ -133,7 +133,7 @@ class AttributeFactory {
 			return $this->newGidAttribute($name,$values,$server_id,$source);
 
 		} else {
-			return new Attribute($name,$values,$server_id,$source);
+			return new PLAAttribute($name,$values,$server_id,$source);
 		}
 	}
 
