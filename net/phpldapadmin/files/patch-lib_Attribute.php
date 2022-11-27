--- lib/Attribute.php.orig	2021-12-12 02:35:51 UTC
+++ lib/Attribute.php
@@ -133,9 +133,9 @@ class PLAAttribute {
 			debug_log('Entered (%%)',5,0,__FILE__,__LINE__,__METHOD__,$fargs,$this->name);
 
 		if ($real)
-			return $lower ? strtolower($this->name) : $this->name;
+			return $lower ? strtolower((string) $this->name) : $this->name;
 		else
-			return $lower ? strtolower($this->real_attr_name()) : $this->real_attr_name();
+			return $lower ? strtolower((string) $this->real_attr_name()) : $this->real_attr_name();
 	}
 
 	public function getValues() {
@@ -389,7 +389,7 @@ class PLAAttribute {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',5,1,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$this->type = strtolower($type);
+		$this->type = strtolower((string) $type);
 	}
 
 	public function getType() {
@@ -403,7 +403,7 @@ class PLAAttribute {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',5,1,__FILE__,__LINE__,__METHOD__,$fargs);
 
-		$this->ldaptype = strtolower($type);
+		$this->ldaptype = strtolower((string) $type);
 	}
 
 	public function getLDAPtype() {
@@ -671,7 +671,7 @@ class PLAAttribute {
 
 		# Store our Aliases
 		foreach ($sattr->getAliases() as $alias)
-			array_push($this->aliases,strtolower($alias));
+			array_push($this->aliases,strtolower((string) $alias));
 
 		if ($sattr->getIsSingleValue())
 			$this->setMaxValueCount(1);
@@ -840,7 +840,7 @@ class PLAAttribute {
 								'type'=>'warn'));
 				}
 
-		elseif (is_string($values) && (strlen($values) > 0))
+		elseif (is_string($values) && (strlen((string) $values) > 0))
 			$this->values = array($values);
 	}
 
@@ -877,7 +877,7 @@ class PLAAttribute {
 		if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 			debug_log('Entered (%%)',5,1,__FILE__,__LINE__,__METHOD__,$fargs,$this->name);
 
-		return preg_replace('/;.*$/U','',$this->name);
+		return preg_replace('/;.*$/U','',is_null($this->name)? "":$this->name);
 	}
 
 	/**
