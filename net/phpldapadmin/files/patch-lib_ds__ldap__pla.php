--- lib/ds_ldap_pla.php.orig	2021-12-12 02:35:51 UTC
+++ lib/ds_ldap_pla.php
@@ -371,7 +371,7 @@ class ldap_pla extends ldap {
 
 				$tree->addEntry($dn);
 
-				set_cached_item($this->index,'tree','null',$tree);
+				set_cached_item($this->index,$tree,'tree','null');
 
 				run_hook('post_entry_create',array('server_id'=>$this->index,'method'=>$method,'dn'=>$dn,'attrs'=>$entry_array));
 
@@ -403,7 +403,7 @@ class ldap_pla extends ldap {
 				$tree = get_cached_item($this->index,'tree');
 				$tree->delEntry($dn);
 
-				set_cached_item($this->index,'tree','null',$tree);
+				set_cached_item($this->index,$tree,'tree','null');
 
 				run_hook('post_entry_delete',array('server_id'=>$this->index,'method'=>$method,'dn'=>$dn));
 			}
@@ -430,7 +430,7 @@ class ldap_pla extends ldap {
 				$newdn = sprintf('%s,%s',$new_rdn,$container);
 				$tree->renameEntry($dn,$newdn);
 
-				set_cached_item($this->index,'tree','null',$tree);
+				set_cached_item($this->index,$tree,'tree','null');
 
 				run_hook('post_entry_rename',array('server_id'=>$this->index,'method'=>$method,'dn'=>$dn,'rdn'=>$new_rdn,'container'=>$container));
 			}
