--- lib/ds_ldap.php.orig	2021-12-12 02:35:51 UTC
+++ lib/ds_ldap.php
@@ -206,6 +206,7 @@ class ldap extends DS {
 
 		if ($this->getValue('server','port'))
 			$resource = ldap_connect($this->getValue('server','host'),$this->getValue('server','port'));
+	
 		else
 			$resource = ldap_connect($this->getValue('server','host'));
 
@@ -216,7 +217,8 @@ class ldap extends DS {
 			debug_log('LDAP Resource [%s], Host [%s], Port [%s]',16,0,__FILE__,__LINE__,__METHOD__,
 				$resource,$this->getValue('server','host'),$this->getValue('server','port'));
 
-		if (! is_resource($resource))
+		// if (! is_resource($resource))
+		if ( !$resource )
 			debug_dump_backtrace('UNHANDLED, $resource is not a resource',1);
 
 		# Go with LDAP version 3 if possible (needed for renaming and Novell schema fetching)
@@ -328,7 +330,7 @@ class ldap extends DS {
 			}
 		}
 
-		if (! $this->isAnonBindAllowed() && ! trim($userDN))
+		if (! $this->isAnonBindAllowed() && ! trim((string) $userDN))
 			return false;
 
 		# Temporarily set our user details
@@ -337,7 +339,7 @@ class ldap extends DS {
 		$connect = $this->connect($method,false,$new);
 
 		# If we didnt log in...
-		if (! is_resource($connect) || $this->noconnect || ! $this->userIsAllowedLogin($userDN)) {
+		if (!$connect || $this->noconnect || ! $this->userIsAllowedLogin($userDN)) {
 			$this->logout($method);
 
 			return false;
@@ -565,11 +567,11 @@ class ldap extends DS {
 
 	private function fillDNTemplate($user) {
 		foreach($this->getLoginBaseDN() as $base)
-			if(substr_compare($user, $base, -strlen($base)) === 0)
+			if(substr_compare($user, $base, -strlen((string) $base)) === 0)
 				return $user; // $user already passed as DN
 
 		// fill template
-		return sprintf($this->getValue('login', 'bind_dn_template'), preg_replace('/([,\\\\#+<>;"=])/', '\\\\$1', $user));
+		return sprintf($this->getValue('login', 'bind_dn_template'), preg_replace('/([,\\\\#+<>;"=])/', '\\\\$1',is_null( $user)? "": $user));
 	}
 
 	/**
@@ -684,7 +686,7 @@ class ldap extends DS {
 
 		if (! in_array($this->getValue('login','auth_type'), array('sasl','sasl_external'))) {
 			// check if SASL mech uses login from other auth_types
-			if (! in_array(strtolower($this->getValue('sasl', 'mech')), array('plain')))
+			if (! in_array(strtolower((string) $this->getValue('sasl', 'mech')), array('plain')))
 				return false;
 		}
 
@@ -722,7 +724,7 @@ class ldap extends DS {
 		}
 
 		# At the moment, we have only implemented GSSAPI and PLAIN
-		if (! in_array(strtolower($this->getValue('sasl','mech')),array('gssapi','plain'))) {
+		if (! in_array(strtolower((string) $this->getValue('sasl','mech')),array('gssapi','plain'))) {
 			system_message(array(
 				'title'=>_('SASL Method not implemented'),
 				'body'=>sprintf('<b>%s</b>: %s %s',_('Error'),$this->getValue('sasl','mech'),_('has not been implemented yet')),
@@ -731,7 +733,7 @@ class ldap extends DS {
 			return false;
 		}
 
-		if (strtolower($this->getValue('sasl','mech')) == 'plain') {
+		if (strtolower((string) $this->getValue('sasl','mech')) == 'plain') {
 			return @ldap_sasl_bind($resource,NULL,$pass,'PLAIN',
 					       $this->getValue('sasl','realm'),
 					       $login,
@@ -746,14 +748,15 @@ class ldap extends DS {
 		/*
 		# Do we need to rewrite authz_id?
 		if (! isset($CACHE['authz_id']))
-			if (! trim($this->getValue('sasl','authz_id')) && strtolower($this->getValue('sasl','mech')) != 'gssapi') {
+			if (! trim((string) $this->getValue('sasl','authz_id')) && strtolower((string) $this->getValue('sasl','mech')) != 'gssapi') {
 				if (DEBUG_ENABLED)
 					debug_log('Rewriting bind DN [%s] -> authz_id with regex [%s] and replacement [%s].',9,0,__FILE__,__LINE__,__METHOD__,
 						$CACHE['login_dn'],
 						$this->getValue('sasl','authz_id_regex'),
 						$this->getValue('sasl','authz_id_replacement'));
 
-				$CACHE['authz_id'] = @preg_replace($this->getValue('sasl','authz_id_regex'),
+				$CACHE['authz_id'] = @preg_replace($this->getValue('sasl','authz_id_regex'),is_null(
+)? "":
 					$this->getValue('sasl','authz_id_replacement'),$CACHE['login_dn']);
 
 				# Invalid regex?
@@ -1212,14 +1215,14 @@ class ldap extends DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		if (! trim($dn))
+		if (! trim((string) $dn))
 			return $dn;
 
 		# Check if the RDN has a comma and escape it.
 		while (preg_match('/([^\\\\]),(\s*[^=]*\s*),/',$dn))
-			$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*),/','$1\\\\2C$2,',$dn);
+			$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*),/','$1\\\\2C$2,',is_null($dn)? "":$dn);
 
-		$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*)([^,])$/','$1\\\\2C$2$3',$dn);
+		$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*)([^,])$/','$1\\\\2C$2$3',is_null($dn)? "":$dn);
 
 		if (DEBUG_ENABLED)
 			debug_log('Returning (%s)',17,0,__FILE__,__LINE__,__METHOD__,$dn);
@@ -1237,12 +1240,12 @@ class ldap extends DS {
 		if (is_array($dn)) {
 			$a = array();
 			foreach ($dn as $key => $rdn) {
-				$a[$key] = preg_replace_callback('/\\\([0-9A-Fa-f]{2})/', function($m) { return chr(hexdec($m[1])); }, $rdn);
+				$a[$key] = preg_replace_callback('/\\\([0-9A-Fa-f]{2})/', function($m) { return chr(hexdec($m[1])); },is_null( $rdn)? "": $rdn);
 			}
 			return $a;
 
 		} else {
-			return preg_replace_callback('/\\\([0-9A-Fa-f]{2})/', function($m) { return chr(hexdec($m[1])); }, $dn);
+			return preg_replace_callback('/\\\([0-9A-Fa-f]{2})/', function($m) { return chr(hexdec($m[1])); },is_null( $dn)? "": $dn);
 		}
 	}
 
@@ -1388,7 +1391,7 @@ class ldap extends DS {
 			return false;
 
 		# error checking
-		$schema_to_fetch = strtolower($schema_to_fetch);
+		$schema_to_fetch = strtolower((string) $schema_to_fetch);
 
 		if (! is_null($this->_schema_entries) && isset($this->_schema_entries[$schema_to_fetch])) {
 			$schema = $this->_schema_entries[$schema_to_fetch];
@@ -1408,7 +1411,7 @@ class ldap extends DS {
 		$schema_dn = $this->getSchemaDN($method,$dn);
 
 		# Do we need to try again with the Root DSE?
-		if (! $schema_dn && trim($dn))
+		if (! $schema_dn && trim((string) $dn))
 			$schema_dn = $this->getSchemaDN($method,'');
 
 		# Store the eventual schema retrieval in $schema_search
@@ -1609,7 +1612,7 @@ class ldap extends DS {
 					foreach ($entry[$olc_schema] as $schema_definition)
 						/* Schema definitions in child nodes prefix the schema entries with "{n}"
 						  the preg_replace call strips out this prefix. */
-						$schema[] = preg_replace('/^\{\d*\}\(/','(',$schema_definition);
+						$schema[] = preg_replace('/^\{\d*\}\(/','(',is_null($schema_definition)? "":$schema_definition);
 				}
 			}
 
@@ -1672,7 +1675,7 @@ class ldap extends DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',25,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$oclass_name = strtolower($oclass_name);
+		$oclass_name = strtolower((string) $oclass_name);
 		$socs = $this->SchemaObjectClasses($method,$dn);
 
 		# Default return value
@@ -1703,7 +1706,7 @@ class ldap extends DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',25,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$attr_name = strtolower($attr_name);
+		$attr_name = strtolower((string) $attr_name);
 		$sattrs = $this->SchemaAttributes($method,$dn);
 
 		# Default return value
@@ -1752,7 +1755,7 @@ class ldap extends DS {
 			$return = array();
 
 			foreach ($raw as $line) {
-				if (is_null($line) || ! strlen($line))
+				if (is_null($line) || ! strlen((string) $line))
 					continue;
 
 				$object_class = new ObjectClass($line,$this);
@@ -1762,8 +1765,8 @@ class ldap extends DS {
 			# Now go through and reference the parent/child relationships
 			foreach ($return as $oclass)
 				foreach ($oclass->getSupClasses() as $parent_name)
-					if (isset($return[strtolower($parent_name)]))
-						$return[strtolower($parent_name)]->addChildObjectClass($oclass->getName(false));
+					if (isset($return[strtolower((string) $parent_name)]))
+						$return[strtolower((string) $parent_name)]->addChildObjectClass($oclass->getName(false));
 
 			ksort($return);
 
@@ -1816,7 +1819,7 @@ class ldap extends DS {
 			 */
 			$attrs_oid = array();
 			foreach ($raw as $line) {
-				if (is_null($line) || ! strlen($line))
+				if (is_null($line) || ! strlen((string) $line))
 					continue;
 
 				$attr = new AttributeType($line);
@@ -1847,7 +1850,7 @@ class ldap extends DS {
 						$new_attr->setName($alias_attr_name);
 						$new_attr->addAlias($attr->getName(false));
 						$new_attr->removeAlias($alias_attr_name);
-						$new_attr_key = strtolower($alias_attr_name);
+						$new_attr_key = strtolower((string) $alias_attr_name);
 						$attrs[$new_attr_key] = $new_attr;
 					}
 				}
@@ -1858,7 +1861,7 @@ class ldap extends DS {
 				$sup_attr_name = $attr->getSupAttribute();
 				$sup_attr = null;
 
-				if (trim($sup_attr_name)) {
+				if (trim((string) $sup_attr_name)) {
 
 					/* This loop really should traverse infinite levels of inheritance (SUP) for attributeTypes,
 					 * but just in case we get carried away, stop at 100. This shouldn't happen, but for
@@ -1871,17 +1874,17 @@ class ldap extends DS {
 							$sup_attr_name = $attr->getSupAttribute();
 						}
 
-						if (! isset($attrs[strtolower($sup_attr_name)])){
+						if (! isset($attrs[strtolower((string) $sup_attr_name)])){
 							error(sprintf('Schema error: attributeType "%s" inherits from "%s", but attributeType "%s" does not exist.',
 								$attr->getName(),$sup_attr_name,$sup_attr_name),'error','index.php');
 							return;
 						}
 
-						$sup_attr = $attrs[strtolower($sup_attr_name)];
+						$sup_attr = $attrs[strtolower((string) $sup_attr_name)];
 						$sup_attr_name = $sup_attr->getSupAttribute();
 
 						# Does this superior attributeType not have a superior attributeType?
-						if (is_null($sup_attr_name) || strlen(trim($sup_attr_name)) == 0) {
+						if (is_null($sup_attr_name) || strlen((string) trim((string) $sup_attr_name)) == 0) {
 
 							/* Since this attribute's superior attribute does not have another superior
 							 * attribute, clone its properties for this attribute. Then, replace
@@ -1936,18 +1939,18 @@ class ldap extends DS {
 
 				# Add Used In.
 				foreach ($oclass_attrs as $attr_name)
-					if (isset($attrs[strtolower($attr_name)]))
-						$attrs[strtolower($attr_name)]->addUsedInObjectClass($object_class->getName(false));
+					if (isset($attrs[strtolower((string) $attr_name)]))
+						$attrs[strtolower((string) $attr_name)]->addUsedInObjectClass($object_class->getName(false));
 
 				# Add Required By.
 				foreach ($must_attrs as $attr_name)
-					if (isset($attrs[strtolower($attr_name)]))
-						$attrs[strtolower($attr_name)]->addRequiredByObjectClass($object_class->getName(false));
+					if (isset($attrs[strtolower((string) $attr_name)]))
+						$attrs[strtolower((string) $attr_name)]->addRequiredByObjectClass($object_class->getName(false));
 
 				# Force May
 				foreach ($object_class->getForceMayAttrs() as $attr_name)
-					if (isset($attrs[strtolower($attr_name->name)]))
-						$attrs[strtolower($attr_name->name)]->setForceMay();
+					if (isset($attrs[strtolower((string) $attr_name->name)]))
+						$attrs[strtolower((string) $attr_name->name)]->setForceMay();
 			}
 
 			$return = $attrs;
@@ -1987,7 +1990,7 @@ class ldap extends DS {
 			$rules = array();
 
 			foreach ($raw as $line) {
-				if (is_null($line) || ! strlen($line))
+				if (is_null($line) || ! strlen((string) $line))
 					continue;
 
 				$rule = new MatchingRule($line);
@@ -2003,7 +2006,7 @@ class ldap extends DS {
 
 			if ($raw != false) {
 				foreach ($raw as $line) {
-					if (is_null($line) || ! strlen($line))
+					if (is_null($line) || ! strlen((string) $line))
 						continue;
 
 					$rule_use = new MatchingRuleUse($line);
@@ -2019,7 +2022,7 @@ class ldap extends DS {
 				$sattrs = $this->SchemaAttributes($method,$dn);
 				if (is_array($sattrs))
 					foreach ($sattrs as $attr) {
-						$rule_key = strtolower($attr->getEquality());
+						$rule_key = strtolower((string) $attr->getEquality());
 
 						if (isset($rules[$rule_key]))
 							$rules[$rule_key]->addUsedByAttr($attr->getName(false));
@@ -2063,11 +2066,11 @@ class ldap extends DS {
 			$return = array();
 
 			foreach ($raw as $line) {
-				if (is_null($line) || ! strlen($line))
+				if (is_null($line) || ! strlen((string) $line))
 					continue;
 
 				$syntax = new Syntax($line);
-				$key = strtolower(trim($syntax->getOID()));
+				$key = strtolower((string) trim((string) $syntax->getOID()));
 
 				if (! $key)
 					continue;
@@ -2097,7 +2100,7 @@ class ldap extends DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		return in_array($attr_name,unserialize(strtolower(serialize($this->getValue('server','force_may')))));
+		return in_array($attr_name,unserialize(strtolower((string) serialize($this->getValue('server','force_may')))));
 	}
 
 	/**
@@ -2133,7 +2136,7 @@ class ldap extends DS {
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		# Ensure our attr is in lowercase
-		$attr = strtolower($attr);
+		$attr = strtolower((string) $attr);
 
 		$values = $this->getDNAttrValues($dn,$method,$deref);
 
@@ -2247,7 +2250,7 @@ class ldap extends DS {
 		# Simple test first
 		$dn_attrs = array('aliasedObjectName');
 		foreach ($dn_attrs as $dn_attr)
-			if (strcasecmp($attr_name,$dn_attr) == 0)
+			if (strcasecmp((string) $attr_name,(string) $dn_attr) == 0)
 				return true;
 
 		# Now look at the schema OID
@@ -2266,7 +2269,7 @@ class ldap extends DS {
 			return false;
 
 		$syntax_desc = $syntaxes[ $syntax_oid ]->getDescription();
-		if (strpos(strtolower($syntax_desc),'distinguished name'))
+		if (strpos(strtolower((string) $syntax_desc),'distinguished name'))
 			return true;
 
 		return false;
@@ -2286,7 +2289,7 @@ class ldap extends DS {
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		# easy quick check
-		if (! strcasecmp($attr_name,'jpegPhoto') || ! strcasecmp($attr_name,'photo'))
+		if (! strcasecmp((string) $attr_name,'jpegPhoto') || ! strcasecmp((string) $attr_name,'photo'))
 			return true;
 
 		# go to the schema and get the Syntax OID
@@ -2297,7 +2300,7 @@ class ldap extends DS {
 		$oid = $sattr->getSyntaxOID();
 		$type = $sattr->getType();
 
-		if (! strcasecmp($type,'JPEG') || ($oid == '1.3.6.1.4.1.1466.115.121.1.28'))
+		if (! strcasecmp((string) $type,'JPEG') || ((string) $oid == '1.3.6.1.4.1.1466.115.121.1.28'))
 			return true;
 
 		return false;
@@ -2318,9 +2321,9 @@ class ldap extends DS {
 
 		$type = ($sattr = $this->getSchemaAttribute($attr_name)) ? $sattr->getType() : null;
 
-		if (! strcasecmp('boolean',$type) ||
-			! strcasecmp('isCriticalSystemObject',$attr_name) ||
-			! strcasecmp('showInAdvancedViewOnly',$attr_name))
+		if (! strcasecmp('boolean',(string) $type) ||
+			! strcasecmp('isCriticalSystemObject',(string) $attr_name) ||
+			! strcasecmp('showInAdvancedViewOnly',(string) $attr_name))
 			return true;
 
 		else
@@ -2359,7 +2362,7 @@ class ldap extends DS {
 
 		static $attr_cache;
 
-		$attr_name = strtolower($attr_name);
+		$attr_name = strtolower((string) $attr_name);
 
 		if (isset($attr_cache[$this->index][$attr_name]))
 			return $attr_cache[$this->index][$attr_name];
@@ -2370,7 +2373,7 @@ class ldap extends DS {
 		}
 
 		# Quick check: If the attr name ends in ";binary", then it's binary.
-		if (strcasecmp(substr($attr_name,strlen($attr_name) - 7),';binary') == 0) {
+		if (strcasecmp(substr((string) $attr_name,strlen((string) (string) $attr_name) - 7),';binary') == 0) {
 			$attr_cache[$this->index][$attr_name] = true;
 			return true;
 		}
@@ -2389,17 +2392,17 @@ class ldap extends DS {
 			$syntax = $sattr->getSyntaxOID();
 		}
 
-		if (strcasecmp($type,'Certificate') == 0 ||
-			strcasecmp($type,'Binary') == 0 ||
-			strcasecmp($attr_name,'usercertificate') == 0 ||
-			strcasecmp($attr_name,'usersmimecertificate') == 0 ||
-			strcasecmp($attr_name,'networkaddress') == 0 ||
-			strcasecmp($attr_name,'objectGUID') == 0 ||
-			strcasecmp($attr_name,'objectSID') == 0 ||
-			strcasecmp($attr_name,'auditingPolicy') == 0 ||
-			strcasecmp($attr_name,'jpegPhoto') == 0 ||
-			strcasecmp($attr_name,'krbExtraData') == 0 ||
-			strcasecmp($attr_name,'krbPrincipalKey') == 0 ||
+		if (strcasecmp((string) $type,'Certificate') == 0 ||
+			strcasecmp((string) $type,'Binary') == 0 ||
+			strcasecmp((string) $attr_name,'usercertificate') == 0 ||
+			strcasecmp((string) $attr_name,'usersmimecertificate') == 0 ||
+			strcasecmp((string) $attr_name,'networkaddress') == 0 ||
+			strcasecmp((string) $attr_name,'objectGUID') == 0 ||
+			strcasecmp((string) $attr_name,'objectSID') == 0 ||
+			strcasecmp((string) $attr_name,'auditingPolicy') == 0 ||
+			strcasecmp((string) $attr_name,'jpegPhoto') == 0 ||
+			strcasecmp((string) $attr_name,'krbExtraData') == 0 ||
+			strcasecmp((string) $attr_name,'krbPrincipalKey') == 0 ||
 			$syntax == '1.3.6.1.4.1.1466.115.121.1.10' ||
 			$syntax == '1.3.6.1.4.1.1466.115.121.1.28' ||
 			$syntax == '1.3.6.1.4.1.1466.115.121.1.5' ||
@@ -2428,7 +2431,7 @@ class ldap extends DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$user = strtolower($user);
+		$user = strtolower((string) $user);
 		$group = $this->getDNAttrValues($group);
 
 		# If you are using groupOfNames objectClass
@@ -2459,7 +2462,7 @@ class ldap extends DS {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',17,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$dn = trim(strtolower($dn));
+		$dn = trim((string) strtolower((string) $dn));
 
 		if (! $this->getValue('login','allowed_dns'))
 			return true;
@@ -2498,7 +2501,7 @@ class ldap extends DS {
                                     debug_log('Comparing with [%s]',80,0,__FILE__,__LINE__,__METHOD__,$result_dn);
 
                                 # Check if $result_dn is a user DN
-                                if (strcasecmp($dn,trim(strtolower($result_dn))) == 0)
+                                if (strcasecmp((string) $dn,trim((string) strtolower((string) (string) $result_dn))) == 0)
                                     return true;
 
                                 # Check if $result_dn is a group DN
@@ -2510,7 +2513,7 @@ class ldap extends DS {
             }
 
             # Check if $login_allowed_dn is a user DN
-            if (strcasecmp($dn,trim(strtolower($login_allowed_dn))) == 0)
+            if (strcasecmp((string) $dn,trim((string) strtolower((string) (string) $login_allowed_dn))) == 0)
                 return true;
 
             # Check if $login_allowed_dn is a group DN
