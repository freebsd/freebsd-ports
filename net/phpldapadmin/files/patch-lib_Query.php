--- lib/Query.php.orig	2021-12-12 02:35:51 UTC
+++ lib/Query.php
@@ -87,9 +87,9 @@ class Query extends xmlTemplate {
 					if (in_array($xml_key,$storelower))
 						if (is_array($xml_value))
 							foreach ($xml_value as $index => $value)
-								$xml_value[$index] = strtolower($value);
+								$xml_value[$index] = strtolower((string) $value);
 						else
-							$xml_value = strtolower($xml_value);
+							$xml_value = strtolower((string) $xml_value);
 
 					# Items that must be stored as arrays
 					if (in_array($xml_key,$storearray) && ! is_array($xml_value))
@@ -109,7 +109,7 @@ class Query extends xmlTemplate {
 		# Check we have some manditory items.
 		foreach (array() as $key) {
 			if (! isset($this->$key)
-				|| (! is_array($this->$key) && ! trim($this->$key))) {
+				|| (! is_array($this->$key) && ! trim((string) $this->$key))) {
 
 				$this->setInvalid(sprintf(_('Missing %s in the XML file.'),$key));
 				break;
@@ -138,7 +138,7 @@ class Query extends xmlTemplate {
 			$query['scope'] = get_request('scope','REQUEST',false,'sub');
 			$attrs = get_request('display_attrs','REQUEST');
 
-			$attrs = preg_replace('/\s+/','',$attrs);
+			$attrs = preg_replace('/\s+/','',is_null($attrs)? "":$attrs);
 			if ($attrs)
 				$query['attrs'] = explode(',',$attrs);
 			else
@@ -198,9 +198,9 @@ class Query extends xmlTemplate {
 	public function getDNEncode($url=true) {
 		// @todo Be nice to do all this in 1 location
 		if ($url)
-			return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->dn));
+			return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->dn)? "":$this->dn));
 		else
-			return preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->dn);
+			return preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->dn)? "":$this->dn);
 	}
 
 	public function getAttrSortOrder() {
@@ -216,9 +216,9 @@ class Query extends xmlTemplate {
 				array_push($result,$attribute->getName());
 
 		} else {
-			$display = preg_replace('/,\s+/',',',get_request('orderby','REQUEST',false,'dn'));
+			$display = preg_replace('/,\s+/',',',get_request('orderby','REQUEST',false,is_null('dn')? "":'dn'));
 
-			if (trim($display))
+			if (trim((string) $display))
 				$result = explode(',',$display);
 		}
 
@@ -238,9 +238,9 @@ class Query extends xmlTemplate {
 				array_push($result,$attribute->getName());
 
 		} else {
-			$display = preg_replace('/,\s+/',',',get_request('display_attrs','REQUEST',false,''));
+			$display = preg_replace('/,\s+/',',',get_request('display_attrs','REQUEST',false,is_null('')? "":''));
 
-			if (trim($display))
+			if (trim((string) $display))
 				$result = explode(',',$display);
 		}
 
