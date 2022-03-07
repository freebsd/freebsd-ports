--- lib/Tree.php.orig	2021-12-12 02:35:51 UTC
+++ lib/Tree.php
@@ -68,7 +68,7 @@ abstract class Tree {
 				}
 			}
 
-			set_cached_item($server_id,'tree','null',$tree);
+			set_cached_item($server_id,$tree,'tree','null');
 		}
 
 		return $tree;
