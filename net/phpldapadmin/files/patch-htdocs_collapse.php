--- htdocs/collapse.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/collapse.php
@@ -19,7 +19,7 @@ $dn = get_request('dn','GET',true);
 $tree = get_cached_item($app['server']->getIndex(),'tree');
 $entry = $tree->getEntry($dn);
 $entry->close();
-set_cached_item($app['server']->getIndex(),'tree','null',$tree);
+set_cached_item($app['server']->getIndex(),$tree,'tree','null');
 
 header(sprintf('Location:index.php?server_id=%s&junk=%s#%s%s',
 	$app['server']->getIndex(),random_junk(),htmlid($app['server']->getIndex(),$dn),app_session_param()));
