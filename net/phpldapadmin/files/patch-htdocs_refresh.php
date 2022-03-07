--- htdocs/refresh.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/refresh.php
@@ -34,7 +34,7 @@ if (get_request('purge','REQUEST')) {
 		$entry->open();
 	}
 
-	set_cached_item($app['server']->getIndex(),'tree','null',$tree);
+	set_cached_item($app['server']->getIndex(),$tree,'tree','null');
 }
 
 if (get_request('meth','REQUEST') == 'ajax') 
