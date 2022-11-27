--- lib/schema_functions.php.orig	2021-12-12 02:35:51 UTC
+++ lib/schema_functions.php
@@ -74,7 +74,7 @@ abstract class SchemaItem {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',9,1,__FILE__,__LINE__,__METHOD__,$fargs,$this->name);
 
-		return $lower ? strtolower($this->name) : $this->name;
+		return $lower ? strtolower((string) $this->name) : $this->name;
 	}
 }
 
@@ -125,7 +125,7 @@ class ObjectClass extends SchemaItem {
 					if ($strings[$i+1]!='(') {
 						do {
 							$i++;
-							if (strlen($this->name) == 0)
+							if (strlen((string) $this->name) == 0)
 								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -136,7 +136,7 @@ class ObjectClass extends SchemaItem {
 						$i++;
 						do {
 							$i++;
-							if (strlen($this->name) == 0)
+							if (strlen((string) $this->name) == 0)
 								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -148,8 +148,8 @@ class ObjectClass extends SchemaItem {
 						} while (! preg_match('/\)+\)?/',$strings[$i]));
 					}
 
-					$this->name = preg_replace('/^\'/','',$this->name);
-					$this->name = preg_replace('/\'$/','',$this->name);
+					$this->name = preg_replace('/^\'/','',is_null($this->name)? "":$this->name);
+					$this->name = preg_replace('/\'$/','',is_null($this->name)? "":$this->name);
 
 					if (DEBUG_ENABLED)
 						debug_log('Case NAME returned (%s)',8,0,__FILE__,__LINE__,__METHOD__,$this->name);
@@ -158,7 +158,7 @@ class ObjectClass extends SchemaItem {
 				case 'DESC':
 					do {
 						$i++;
-						if (strlen($this->description) == 0)
+						if (strlen((string) $this->description) == 0)
 							$this->description=$this->description.$strings[$i];
 						else
 							$this->description=$this->description.' '.$strings[$i];
@@ -179,14 +179,14 @@ class ObjectClass extends SchemaItem {
 				case 'SUP':
 					if ($strings[$i+1] != '(') {
 						$i++;
-						array_push($this->sup_classes,preg_replace("/'/",'',$strings[$i]));
+						array_push($this->sup_classes,preg_replace("/'/",'',is_null($strings[$i])? "":$strings[$i]));
 
 					} else {
 						$i++;
 						do {
 							$i++;
 							if ($strings[$i] != '$')
-								array_push($this->sup_classes,preg_replace("/'/",'',$strings[$i]));
+								array_push($this->sup_classes,preg_replace("/'/",'',is_null($strings[$i])? "":$strings[$i]));
 
 						} while (! preg_match('/\)+\)?/',$strings[$i+1]));
 					}
@@ -267,8 +267,8 @@ class ObjectClass extends SchemaItem {
 			}
 		}
 
-		$this->description = preg_replace("/^\'/",'',$this->description);
-		$this->description = preg_replace("/\'$/",'',$this->description);
+		$this->description = preg_replace("/^\'/",'',is_null($this->description)? "":$this->description);
+		$this->description = preg_replace("/\'$/",'',is_null($this->description)? "":$this->description);
 
 		if (DEBUG_ENABLED)
 			debug_log('Returning () - NAME (%s), DESCRIPTION (%s), MUST (%s), MAY (%s), FORCE MAY (%s)',9,0,__FILE__,__LINE__,__METHOD__,
@@ -293,13 +293,13 @@ class ObjectClass extends SchemaItem {
 		if (! preg_match('/^\(/',$string)) {
 			# A bareword only - can be terminated by a ) if the last item
 			if (preg_match('/\)+$/',$string))
-				$string = preg_replace('/\)+$/','',$string);
+				$string = preg_replace('/\)+$/','',is_null($string)? "":$string);
 
 			array_push($attrs,$string);
 
 		} elseif (preg_match('/^\(.*\)$/',$string)) {
-			$string = preg_replace('/^\(/','',$string);
-			$string = preg_replace('/\)+$/','',$string);
+			$string = preg_replace('/^\(/','',is_null($string)? "":$string);
+			$string = preg_replace('/\)+$/','',is_null($string)? "":$string);
 			array_push($attrs,$string);
 
 		} else {
@@ -308,7 +308,7 @@ class ObjectClass extends SchemaItem {
 				$i++;
 
 			} elseif (preg_match('/^\(./',$string)) {
-				$string = preg_replace('/^\(/','',$string);
+				$string = preg_replace('/^\(/','',is_null($string)? "":$string);
 				array_push($attrs,$string);
 				$i++;
 			}
@@ -323,7 +323,7 @@ class ObjectClass extends SchemaItem {
 				}
 
 				if (preg_match('/\)$/',$string))
-					$string = preg_replace('/\)+$/','',$string);
+					$string = preg_replace('/\)+$/','',is_null($string)? "":$string);
 				else
 					$i++;
 
@@ -519,10 +519,10 @@ class ObjectClass extends SchemaItem {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',9,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$name = trim($name);
+		$name = trim((string) $name);
 
 		foreach ($this->children_objectclasses as $existing_objectclass)
-			if (strcasecmp($name,$existing_objectclass) == 0)
+			if (strcasecmp((string) $name,(string) $existing_objectclass) == 0)
 				return false;
 
 		array_push($this->children_objectclasses,$name);
@@ -683,7 +683,7 @@ class ObjectClass_ObjectClassAttribute {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',9,1,__FILE__,__LINE__,__METHOD__,$fargs,$this->name);
 
-		return $lower ? strtolower($this->name) : $this->name;
+		return $lower ? strtolower((string) $this->name) : $this->name;
 	}
 
 	# Gets the name of the ObjectClass which originally specified this attribute.
@@ -754,7 +754,7 @@ class AttributeType extends SchemaItem {
 					if ($strings[$i+1] != '(' && ! preg_match('/^\(/',$strings[$i+1])) {
 						do {
 							$i++;
-							if (strlen($this->name)==0)
+							if (strlen((string) $this->name)==0)
 								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -769,11 +769,11 @@ class AttributeType extends SchemaItem {
 						do {
 							# In case we came here becaues of a ('
 							if (preg_match('/^\(/',$strings[$i]))
-								$strings[$i] = preg_replace('/^\(/','',$strings[$i]);
+								$strings[$i] = preg_replace('/^\(/','',is_null($strings[$i])? "":$strings[$i]);
 							else
 								$i++;
 
-							if (strlen($this->name) == 0)
+							if (strlen((string) $this->name) == 0)
  								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -783,8 +783,8 @@ class AttributeType extends SchemaItem {
 						# Add alias names for this attribute
 						while ($strings[++$i] != ')') {
 							$alias = $strings[$i];
-							$alias = preg_replace("/^\'/",'',$alias);
-							$alias = preg_replace("/\'$/",'',$alias);
+							$alias = preg_replace("/^\'/",'',is_null($alias)? "":$alias);
+							$alias = preg_replace("/\'$/",'',is_null($alias)? "":$alias);
 							$this->addAlias($alias);
 						}
 					}
@@ -796,7 +796,7 @@ class AttributeType extends SchemaItem {
 				case 'DESC':
 					do {
 						$i++;
-						if (strlen($this->description)==0)
+						if (strlen((string) $this->description)==0)
 							$this->description=$this->description.$strings[$i];
 						else
 							$this->description=$this->description.' '.$strings[$i];
@@ -848,7 +848,7 @@ class AttributeType extends SchemaItem {
 				case 'SYNTAX':
 					$i++;
 					$this->syntax = $strings[$i];
-					$this->syntax_oid = preg_replace('/{\d+}$/','',$this->syntax);
+					$this->syntax_oid = preg_replace('/{\d+}$/','',is_null($this->syntax)? "":$this->syntax);
 
 					# Does this SYNTAX string specify a max length (ie, 1.2.3.4{16})
 					if (preg_match('/{(\d+)}$/',$this->syntax,$this->max_length))
@@ -906,16 +906,16 @@ class AttributeType extends SchemaItem {
 			}
 		}
 
-		$this->name = preg_replace("/^\'/",'',$this->name);
-		$this->name = preg_replace("/\'$/",'',$this->name);
-		$this->description = preg_replace("/^\'/",'',$this->description);
-		$this->description = preg_replace("/\'$/",'',$this->description);
-		$this->syntax = preg_replace("/^\'/",'',$this->syntax);
-		$this->syntax = preg_replace("/\'$/",'',$this->syntax);
-		$this->syntax_oid = preg_replace("/^\'/",'',$this->syntax_oid);
-		$this->syntax_oid = preg_replace("/\'$/",'',$this->syntax_oid);
-		$this->sup_attribute = preg_replace("/^\'/",'',$this->sup_attribute);
-		$this->sup_attribute = preg_replace("/\'$/",'',$this->sup_attribute);
+		$this->name = preg_replace("/^\'/",'',is_null($this->name)? "":$this->name);
+		$this->name = preg_replace("/\'$/",'',is_null($this->name)? "":$this->name);
+		$this->description = preg_replace("/^\'/",'',is_null($this->description)? "":$this->description);
+		$this->description = preg_replace("/\'$/",'',is_null($this->description)? "":$this->description);
+		$this->syntax = preg_replace("/^\'/",'',is_null($this->syntax)? "":$this->syntax);
+		$this->syntax = preg_replace("/\'$/",'',is_null($this->syntax)? "":$this->syntax);
+		$this->syntax_oid = preg_replace("/^\'/",'',is_null($this->syntax_oid)? "":$this->syntax_oid);
+		$this->syntax_oid = preg_replace("/\'$/",'',is_null($this->syntax_oid)? "":$this->syntax_oid);
+		$this->sup_attribute = preg_replace("/^\'/",'',is_null($this->sup_attribute)? "":$this->sup_attribute);
+		$this->sup_attribute = preg_replace("/\'$/",'',is_null($this->sup_attribute)? "":$this->sup_attribute);
 
 		if (DEBUG_ENABLED)
 			debug_log('Returning ()',9,0,__FILE__,__LINE__,__METHOD__);
@@ -1006,7 +1006,7 @@ class AttributeType extends SchemaItem {
 			debug_log('Entered (%%)',9,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		foreach ($this->aliases as $alias_attr_name)
-			if (strcasecmp($alias_attr_name,$attr_name) == 0)
+			if (strcasecmp((string) $alias_attr_name,(string) $attr_name) == 0)
 				return true;
 
 		return false;
@@ -1125,7 +1125,7 @@ class AttributeType extends SchemaItem {
 
 		foreach ($this->aliases as $i => $alias_name) {
 
-			if (strcasecmp($alias_name,$remove_alias_name) == 0) {
+			if (strcasecmp((string) $alias_name,(string) $remove_alias_name) == 0) {
 				unset($this->aliases[$i]);
 
 				$this->aliases = array_values($this->aliases);
@@ -1209,7 +1209,7 @@ class AttributeType extends SchemaItem {
 			if (DEBUG_ENABLED)
 				debug_log('Checking (%s) with (%s)',8,0,__FILE__,__LINE__,__METHOD__,$used_in_object_class,$name);
 
-			if (strcasecmp($used_in_object_class,$name) == 0)
+			if (strcasecmp((string) $used_in_object_class,(string) $name) == 0)
 				return false;
 		}
 
@@ -1240,7 +1240,7 @@ class AttributeType extends SchemaItem {
 			debug_log('Entered (%%)',9,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		foreach ($this->required_by_object_classes as $required_by_object_class)
-			if (strcasecmp($required_by_object_class,$name) == 0)
+			if (strcasecmp((string) $required_by_object_class,(string) $name) == 0)
 				return false;
 
 		array_push($this->required_by_object_classes,$name);
@@ -1301,7 +1301,7 @@ class Syntax extends SchemaItem {
 				case 'DESC':
 					do {
 						$i++;
-						if (strlen($this->description) == 0)
+						if (strlen((string) $this->description) == 0)
 							$this->description=$this->description.$strings[$i];
 						else
 							$this->description=$this->description.' '.$strings[$i];
@@ -1314,8 +1314,8 @@ class Syntax extends SchemaItem {
 			}
 		}
 
-		$this->description = preg_replace("/^\'/",'',$this->description);
-		$this->description = preg_replace("/\'$/",'',$this->description);
+		$this->description = preg_replace("/^\'/",'',is_null($this->description)? "":$this->description);
+		$this->description = preg_replace("/\'$/",'',is_null($this->description)? "":$this->description);
 	}
 }
 
@@ -1349,7 +1349,7 @@ class MatchingRule extends SchemaItem {
 					if ($strings[$i+1] != '(') {
 						do {
 							$i++;
-							if (strlen($this->name) == 0)
+							if (strlen((string) $this->name) == 0)
 								$this->name = $strings[$i];
 						else
 								$this->name .= ' '.$strings[$i];
@@ -1359,7 +1359,7 @@ class MatchingRule extends SchemaItem {
 						$i++;
 						do {
 							$i++;
-							if (strlen($this->name) == 0)
+							if (strlen((string) $this->name) == 0)
 								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -1370,14 +1370,14 @@ class MatchingRule extends SchemaItem {
 						} while (! preg_match('/\)+\)?/',$strings[$i]));
 					}
 
-					$this->name = preg_replace("/^\'/",'',$this->name);
-					$this->name = preg_replace("/\'$/",'',$this->name);
+					$this->name = preg_replace("/^\'/",'',is_null($this->name)? "":$this->name);
+					$this->name = preg_replace("/\'$/",'',is_null($this->name)? "":$this->name);
 					break;
 
 				case 'DESC':
 					do {
 						$i++;
-						if (strlen($this->description)==0)
+						if (strlen((string) $this->description)==0)
 							$this->description=$this->description.$strings[$i];
 						else
 							$this->description=$this->description.' '.$strings[$i];
@@ -1397,8 +1397,8 @@ class MatchingRule extends SchemaItem {
 						$this->setOID($strings[$i]);
 			}
 		}
-		$this->description = preg_replace("/^\'/",'',$this->description);
-		$this->description = preg_replace("/\'$/",'',$this->description);
+		$this->description = preg_replace("/^\'/",'',is_null($this->description)? "":$this->description);
+		$this->description = preg_replace("/\'$/",'',is_null($this->description)? "":$this->description);
 	}
 
 	/**
@@ -1423,7 +1423,7 @@ class MatchingRule extends SchemaItem {
 			debug_log('Entered (%%)',9,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		foreach ($this->used_by_attrs as $attr_name)
-			if (strcasecmp($attr_name,$attr) == 0)
+			if (strcasecmp((string) $attr_name,(string) $attr) == 0)
 				return false;
 
 		array_push($this->used_by_attrs,$attr);
@@ -1469,7 +1469,7 @@ class MatchingRuleUse extends SchemaItem {
 					if ($strings[$i+1] != '(') {
 						do {
 							$i++;
-							if (! isset($this->name) || strlen($this->name) == 0)
+							if (! isset($this->name) || strlen((string) $this->name) == 0)
 								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -1480,7 +1480,7 @@ class MatchingRuleUse extends SchemaItem {
 						$i++;
 						do {
 							$i++;
-							if (strlen($this->name) == 0)
+							if (strlen((string) $this->name) == 0)
 								$this->name = $strings[$i];
 							else
 								$this->name .= ' '.$strings[$i];
@@ -1491,8 +1491,8 @@ class MatchingRuleUse extends SchemaItem {
 						} while (! preg_match('/\)+\)?/',$strings[$i]));
 					}
 
-					$this->name = preg_replace("/^\'/",'',$this->name);
-					$this->name = preg_replace("/\'$/",'',$this->name);
+					$this->name = preg_replace("/^\'/",'',is_null($this->name)? "":$this->name);
+					$this->name = preg_replace("/\'$/",'',is_null($this->name)? "":$this->name);
 					break;
 
 				case 'APPLIES':
@@ -1507,8 +1507,8 @@ class MatchingRuleUse extends SchemaItem {
 						while ($strings[$i] != ')') {
 							$i++;
 							$new_attr = $strings[$i];
-							$new_attr = preg_replace("/^\'/",'',$new_attr);
-							$new_attr = preg_replace("/\'$/",'',$new_attr);
+							$new_attr = preg_replace("/^\'/",'',is_null($new_attr)? "":$new_attr);
+							$new_attr = preg_replace("/\'$/",'',is_null($new_attr)? "":$new_attr);
 							array_push($this->used_by_attrs,$new_attr);
 							$i++;
 						}
