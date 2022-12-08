--- lib/Tree.php.orig	2021-12-12 02:35:51 UTC
+++ lib/Tree.php
@@ -68,7 +68,7 @@ abstract class Tree {
 				}
 			}
 
-			set_cached_item($server_id,'tree','null',$tree);
+			set_cached_item($server_id,$tree,'tree','null');
 		}
 
 		return $tree;
@@ -132,7 +132,7 @@ abstract class Tree {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',33,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$index = strtolower(implode(',',pla_explode_dn($dn)));
+		$index = strtolower((string) implode(',',pla_explode_dn($dn)));
 
 		if (DEBUG_ENABLED)
 			debug_log('Result (%s)',1,0,__FILE__,__LINE__,__METHOD__,$index);
@@ -185,7 +185,7 @@ abstract class Tree {
 		$tree_factory = new TreeItem($server->getIndex(),$dn);
 		$tree_factory->setObjectClasses($server->getDNAttrValue($dn,'objectClass'));
 
-		if ((($isleaf = $server->getDNAttrValue($dn,'hassubordinates')) && ! strcasecmp($isleaf[0],'false')))
+		if ((($isleaf = $server->getDNAttrValue($dn,'hassubordinates')) && ! strcasecmp((string) $isleaf[0],'false')))
 			$tree_factory->setLeaf();
 
 		$this->entries[$dnlower] = $tree_factory;
