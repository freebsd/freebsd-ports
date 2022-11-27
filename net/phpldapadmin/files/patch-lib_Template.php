--- lib/Template.php.orig	2021-12-12 02:35:51 UTC
+++ lib/Template.php
@@ -100,7 +100,7 @@ class Template extends xmlTemplate {
 							foreach ($xmldata['template'][$xml_key]['objectclass'] as $index => $details) {
 
 								# XML files with only 1 objectClass dont have a numeric index.
-								$soc = $server->getSchemaObjectClass(strtolower($details));
+								$soc = $server->getSchemaObjectClass(strtolower((string) $details));
 
 								# If we havent recorded this objectclass already, do so now.
 								if (is_object($soc) && ! in_array($soc->getName(),$objectclasses))
@@ -115,7 +115,7 @@ class Template extends xmlTemplate {
 
 						} else {
 							# XML files with only 1 objectClass dont have a numeric index.
-							$soc = $server->getSchemaObjectClass(strtolower($xmldata['template'][$xml_key]['objectclass']));
+							$soc = $server->getSchemaObjectClass(strtolower((string) $xmldata['template'][$xml_key]['objectclass']));
 
 							# If we havent recorded this objectclass already, do so now.
 							if (is_object($soc) && ! in_array($soc->getName(),$objectclasses))
@@ -160,9 +160,9 @@ class Template extends xmlTemplate {
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
@@ -198,7 +198,7 @@ class Template extends xmlTemplate {
 		# Check we have some manditory items.
 		foreach (array('rdn','structural_oclass','visible') as $key) {
 			if (! isset($this->$key)
-				|| (! is_array($this->$key) && ! trim($this->$key))) {
+				|| (! is_array($this->$key) && ! trim((string) $this->$key))) {
 
 				$this->setInvalid(sprintf(_('Missing %s in the XML file.'),$key));
 				break;
@@ -272,7 +272,7 @@ class Template extends xmlTemplate {
 					'body'=>sprintf('DN (%s) didnt exist in LDAP?',$this->dn),
 					'type'=>'info'));
 
-			$rdnarray = rdn_explode(strtolower(get_rdn(dn_escape($this->dn))));
+			$rdnarray = rdn_explode(strtolower((string) get_rdn(dn_escape($this->dn))));
 
 			$counter = 1;
 			foreach ($server->getDNAttrValues($this->dn,null,LDAP_DEREF_NEVER,array_merge(array('*'),$server->getValue('server','custom_attrs')),$nocache) as $attr => $values) {
@@ -298,7 +298,7 @@ class Template extends xmlTemplate {
 				# Work out the RDN attributes
 				foreach ($attribute->getValues() as $index => $value)
 					if (in_array(sprintf('%s=%s',
-						$attribute->getName(),strtolower($attribute->getValue($index))),$rdnarray))
+						$attribute->getName(),strtolower((string) $attribute->getValue($index))),$rdnarray))
 						$attribute->setRDN($counter++);
 
 				if ($makeVisible)
@@ -355,7 +355,7 @@ class Template extends xmlTemplate {
 
 					# Prune out entries with a blank value.
 					foreach ($values as $index => $value)
-						if (! strlen(trim($value)))
+						if (! strlen((string) trim((string) $value)))
 							unset($values[$index]);
 
 					$attribute = $this->getAttribute($attr);
@@ -603,7 +603,7 @@ class Template extends xmlTemplate {
 			foreach ($rdnarray as $index => $rdnattr) {
 				list($attr,$value) = explode('=',$rdnattr);
 
-				if (strtolower($attr) == $attribute->getName()) {
+				if (strtolower((string) $attr) == $attribute->getName()) {
 					$attribute->setRDN($counter++);
 					unset($rdnarray[$index]);
 				}
@@ -637,9 +637,9 @@ class Template extends xmlTemplate {
 	public function getDNEncode($url=true) {
 		// @todo Be nice to do all this in 1 location
 		if ($url)
-			return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->getDN()));
+			return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->getDN())? "":$this->getDN()));
 		else
-			return preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->getDN());
+			return preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->getDN())? "":$this->getDN());
 	}
 
 	/**
@@ -676,9 +676,9 @@ class Template extends xmlTemplate {
 	public function getContainerEncode($url=true) {
 		// @todo Be nice to do all this in 1 location
 		if ($url)
-			return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->container));
+			return urlencode(preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->container)? "":$this->container));
 		else
-			return preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",$this->container);
+			return preg_replace('/%([0-9a-fA-F]+)/',"%25\\1",is_null($this->container)? "":$this->container);
 	}
 
 	/**
@@ -707,7 +707,7 @@ class Template extends xmlTemplate {
 				$modified = false;
 				foreach ($rdnarray as $index => $rdnattr) {
 					list($attr,$value) = explode('=',$rdnattr);
-					if (strtolower($attr) == $attribute->getName()) {
+					if (strtolower((string) $attr) == $attribute->getName()) {
 
 						# If this is already marked as an RDN, then this multivalue RDN was updated on a previous loop
 						if (! $modified) {
@@ -726,7 +726,7 @@ class Template extends xmlTemplate {
 			}
 
 			// @todo If this is a Jpeg Attribute, we need to mark it read only, since it cant be deleted like text attributes can
-			if (strcasecmp(get_class($attribute),'jpegAttribute') == 0)
+			if (strcasecmp(get_class((string) $attribute),'jpegAttribute') == 0)
 				$attribute->setReadOnly();
 		}
 
@@ -761,7 +761,7 @@ class Template extends xmlTemplate {
 		$result = array();
 
 		foreach ($this->attributes as $index => $attribute) {
-			if ($attribute->getLDAPtype() == strtolower($type))
+			if ($attribute->getLDAPtype() == strtolower((string) $type))
 				array_push($result,$attribute->getName());
 		}
 
@@ -775,7 +775,7 @@ class Template extends xmlTemplate {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',5,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		if (in_array(strtolower($attr),$this->getAttrbyLdapType($type)))
+		if (in_array(strtolower((string) $attr),$this->getAttrbyLdapType($type)))
 			return true;
 		else
 			return false;
@@ -856,7 +856,7 @@ class Template extends xmlTemplate {
 		}
 
 		# Chop the last plus sign off when returning
-		return preg_replace('/\+$/','',$rdn);
+		return preg_replace('/\+$/','',is_null($rdn)? "":$rdn);
 	}
 
 	/**
@@ -1166,25 +1166,25 @@ class Template extends xmlTemplate {
 					$attribute->js['autoFill'] = '';
 
 				$formula = $string;
-				$formula = preg_replace('/^([^%])/','\'$1',$formula);
-				$formula = preg_replace('/([^%])$/','$1\'',$formula);
+				$formula = preg_replace('/^([^%])/','\'$1',is_null($formula)? "":$formula);
+				$formula = preg_replace('/([^%])$/','$1\'',is_null($formula)? "":$formula);
 
 				# Check that our attributes match our schema attributes.
 				foreach ($matchall[1] as $index => $checkattr) {
 					$sattr = $this->getServer()->getSchemaAttribute($checkattr);
 
 					# If the attribute is the same as in the XML file, then dont need to do anything.
-					if (! $sattr || ! strcasecmp($sattr->getName(),$checkattr))
+					if (! (string) $sattr || ! strcasecmp((string) $sattr->getName(),(string) $checkattr))
 						continue;
 
-					$formula = preg_replace("/$checkattr/",$sattr->getName(),$formula);
+					$formula = preg_replace("/$checkattr/",$sattr->getName(),is_null($formula)? "":$formula);
 					$matchall[1][$index] = $sattr->getName();
 				}
 
 				$elem_id = 0;
 
 				foreach ($matchall[0] as $index => $null) {
-					$match_attr = strtolower($matchall[1][$index]);
+					$match_attr = strtolower((string) $matchall[1][$index]);
 					$match_subst = $matchall[2][$index];
 					$match_mod = $matchall[3][$index];
 					$match_delim = $matchall[4][$index];
@@ -1199,7 +1199,7 @@ class Template extends xmlTemplate {
 					$js_match_attr = $match_attr;
 					$match_attr = $js_match_attr.'xx'.$varcount[$match_attr];
 
-					$formula = preg_replace('/%'.$js_match_attr.'([|\/%])/i','%'.$match_attr.'$1',$formula,1);
+					$formula = preg_replace('/%'.$js_match_attr.'([|\/%])/i','%'.$match_attr.'$1',$formula,is_null(1)? "":1);
 
 					$attribute->js['autoFill'] .= sprintf("  var %s;\n",$match_attr);
 					$attribute->js['autoFill'] .= sprintf(
@@ -1216,7 +1216,7 @@ class Template extends xmlTemplate {
 					$elem_id++;
 
 					if (strstr($match_mod,'k')) {
-						preg_match_all('/([0-9]+)/',trim($match_subst),$substrarray);
+						preg_match_all('/([0-9]+)/',trim((string) $match_subst),$substrarray);
 						if (isset($substrarray[1][0])) {
 							$tok_idx = $substrarray[1][0];
 						} else {
@@ -1225,7 +1225,7 @@ class Template extends xmlTemplate {
 						$attribute->js['autoFill'] .= sprintf("   %s = %s.split(':')[%s];\n",$match_attr,$match_attr,$tok_idx);
 
 					} elseif (strstr($match_mod,'K')) {
-						preg_match_all('/([0-9]+)/',trim($match_subst),$substrarray);
+						preg_match_all('/([0-9]+)/',trim((string) $match_subst),$substrarray);
 						if (isset($substrarray[1][0])) {
 							$tok_idx = $substrarray[1][0];
 						} else {
@@ -1240,7 +1240,7 @@ class Template extends xmlTemplate {
 						$attribute->js['autoFill'] .= sprintf("   %s = %s.split('%s')[%s];\n",$match_attr,$match_attr,$delimiter,$tok_idx);
 
 					} else {
-						preg_match_all('/([0-9]*)-([0-9]*)/',trim($match_subst),$substrarray);
+						preg_match_all('/([0-9]*)-([0-9]*)/',trim((string) $match_subst),$substrarray);
 						if ((isset($substrarray[1][0]) && $substrarray[1][0]) || (isset($substrarray[2][0]) && $substrarray[2][0])) {
 							$attribute->js['autoFill'] .= sprintf("   %s = %s.substr(%s,%s);\n",
 								$match_attr,$match_attr,
@@ -1260,19 +1260,19 @@ class Template extends xmlTemplate {
 					}
 
 					# Matchfor only entry without modifiers.
-					$formula = preg_replace('/^%('.$match_attr.')%$/U','$1 + \'\'',$formula);
+					$formula = preg_replace('/^%('.$match_attr.')%$/U','$1 + \'\'',is_null($formula)? "":$formula);
 					# Matchfor only entry with modifiers.
-					$formula = preg_replace('/^%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%$/U','$1 + \'\'',$formula);
+					$formula = preg_replace('/^%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%$/U','$1 + \'\'',is_null($formula)? "":$formula);
 					# Matchfor begining entry.
-					$formula = preg_replace('/^%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%/U','$1 + \'',$formula);
+					$formula = preg_replace('/^%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%/U','$1 + \'',is_null($formula)? "":$formula);
 					# Matchfor ending entry.
-					$formula = preg_replace('/%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%$/U','\' + $1 ',$formula);
+					$formula = preg_replace('/%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%$/U','\' + $1 ',is_null($formula)? "":$formula);
 					# Match for entries not at begin/end.
-					$formula = preg_replace('/%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%/U','\' + $1 + \'',$formula);
+					$formula = preg_replace('/%('.$match_attr.')(\|[0-9]*-[0-9]*)?(\/[KklTUA]+)?(?:\|(.))?%/U','\' + $1 + \'',is_null($formula)? "":$formula);
 					$attribute->js['autoFill'] .= "\n";
 				}
 
-				$attribute->js['autoFill'] .= sprintf(" fillRec(pre+'%s'+suf, %s); // %s\n",strtolower($attr),$formula,$string);
+				$attribute->js['autoFill'] .= sprintf(" fillRec(pre+'%s'+suf, %s); // %s\n",strtolower((string) $attr),$formula,$string);
 				$attribute->js['autoFill'] .= "\n";
 				break;
 
@@ -1333,7 +1333,7 @@ class Template extends xmlTemplate {
 							$this->setMinValueCount($sattr->getName(),1);
 
 							# We need to mark the attributes as show, except for the objectclass attribute.
-							if (strcasecmp('objectClass',$objectclassattr) != 0) {
+							if (strcasecmp('objectClass',(string) $objectclassattr) != 0) {
 								$attribute = $this->getAttribute($sattr->getName());
 								$attribute->show();
 							}
