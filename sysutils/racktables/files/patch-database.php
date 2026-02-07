--- wwwroot/inc/database.php.orig	2022-02-15 23:54:10 UTC
+++ wwwroot/inc/database.php
@@ -4853,7 +4853,7 @@ function commitAddFile ($name, $type, $contents, $comm
 	}
 }
 
-function commitReplaceFile ($file_id = 0, $contents)
+function commitReplaceFile ($file_id, $contents)
 {
 	global $dbxlink;
 	$query = $dbxlink->prepare('UPDATE File SET mtime = NOW(), contents = ?, size = LENGTH(contents), thumbnail = NULL WHERE id = ?');
@@ -5565,7 +5565,7 @@ function makeVlanListWhere ($db_field_name, $vlan_list
 	return $ret;
 }
 
-function upd8021QPort ($instance = 'desired', $object_id, $port_name, $port, $before)
+function upd8021QPort ($instance, $object_id, $port_name, $port, $before)
 {
 	global $tablemap_8021q;
 	if (!array_key_exists ($instance, $tablemap_8021q))
@@ -5638,7 +5638,7 @@ function upd8021QPort ($instance = 'desired', $object_
 	return $changed ? 1 : 0;
 }
 
-function replace8021QPorts ($instance = 'desired', $object_id, $before, $changes)
+function replace8021QPorts ($instance, $object_id, $before, $changes)
 {
 	$done = 0;
 	foreach ($changes as $pn => $port)
