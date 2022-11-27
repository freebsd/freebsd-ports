--- lib/TreeItem.php.orig	2021-12-12 02:35:51 UTC
+++ lib/TreeItem.php
@@ -59,7 +59,7 @@ class TreeItem {
 	}
 
 	public function getDNEncode() {
-		return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->dn));
+		return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->dn)? "":$this->dn));
 	}
 
 	/**
