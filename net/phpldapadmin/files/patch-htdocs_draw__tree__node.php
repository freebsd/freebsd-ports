--- htdocs/draw_tree_node.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/draw_tree_node.php
@@ -50,7 +50,7 @@ if ($request['dn']) {
 }
 
 if ($treesave)
-	set_cached_item($app['server']->getIndex(),'tree','null',$tree);
+	set_cached_item($app['server']->getIndex(),$tree,'tree','null');
 
 if ($request['dn'])
 	echo $tree->draw_children($dnentry,$request['code']);
