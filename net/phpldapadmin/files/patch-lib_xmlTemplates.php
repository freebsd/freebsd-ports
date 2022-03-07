--- lib/xmlTemplates.php.orig	2021-12-12 02:35:51 UTC
+++ lib/xmlTemplates.php
@@ -140,7 +140,7 @@ abstract class xmlTemplates {
 
 		if ($changed) {
 			masort($this->templates,'title');
-			set_cached_item($server_id,$class['item'],'null',$this->templates);
+			set_cached_item($server_id,$this->templates,$class['item'],'null');
 		}
 	}
 
