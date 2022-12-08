--- lib/AttributeFactory.php.orig	2021-12-12 02:35:51 UTC
+++ lib/AttributeFactory.php
@@ -83,7 +83,7 @@ class AttributeFactory {
 		if (isset($values['type']))
 			switch ($values['type']) {
 				case 'password':
-					if (! strcasecmp($name,'sambaLMPassword') || ! strcasecmp($name,'sambaNTPassword'))
+					if (! strcasecmp((string) $name,'sambaLMPassword') || ! strcasecmp((string) $name,'sambaNTPassword'))
 						return $this->newSambaPasswordAttribute($name,$values,$server_id,$source);
 					else
 						return $this->newPasswordAttribute($name,$values,$server_id,$source);
@@ -96,7 +96,7 @@ class AttributeFactory {
 					return $this->newMultiLineAttribute($name,$values,$server_id,$source);
 			}
 
-		if (! strcasecmp($name,'objectClass')) {
+		if (! strcasecmp((string) $name,'objectClass')) {
 			return $this->newObjectClassAttribute($name,$values,$server_id,$source);
 
 		} elseif ($app['server']->isJpegPhoto($name) || in_array($name,$app['server']->getValue('server','jpeg_attributes'))) {
@@ -105,16 +105,16 @@ class AttributeFactory {
 		} elseif ($app['server']->isAttrBinary($name)) {
 			return $this->newBinaryAttribute($name,$values,$server_id,$source);
 
-		} elseif (! strcasecmp($name,'userPassword')) {
+		} elseif (! strcasecmp((string) $name,'userPassword')) {
 			return $this->newPasswordAttribute($name,$values,$server_id,$source);
 
-		} elseif (! strcasecmp($name,'sambaLMPassword') || ! strcasecmp($name,'sambaNTPassword')) {
+		} elseif (! strcasecmp((string) $name,'sambaLMPassword') || ! strcasecmp((string) $name,'sambaNTPassword')) {
 			return $this->newSambaPasswordAttribute($name,$values,$server_id,$source);
 
-		} elseif (in_array(strtolower($name),array_keys(array_change_key_case($_SESSION[APPCONFIG]->getValue('appearance','date_attrs'))))) {
+		} elseif (in_array(strtolower((string) $name),array_keys(array_change_key_case($_SESSION[APPCONFIG]->getValue('appearance','date_attrs'))))) {
 			return $this->newDateAttribute($name,$values,$server_id,$source);
 
-		} elseif (in_array(strtolower($name),array('shadowlastchange','shadowmin','shadowmax','shadowexpire','shadowwarning','shadowinactive'))) {
+		} elseif (in_array(strtolower((string) $name),array('shadowlastchange','shadowmin','shadowmax','shadowexpire','shadowwarning','shadowinactive'))) {
 			return $this->newShadowAttribute($name,$values,$server_id,$source);
 
 		} elseif ($app['server']->isAttrBoolean($name)) {
@@ -129,11 +129,11 @@ class AttributeFactory {
 		} elseif ($app['server']->isMultiLineAttr($name)) {
 			return $this->newMultiLineAttribute($name,$values,$server_id,$source);
 
-		} elseif (! strcasecmp($name,'gidNumber')) {
+		} elseif (! strcasecmp((string) $name,'gidNumber')) {
 			return $this->newGidAttribute($name,$values,$server_id,$source);
 
 		} else {
-			return new Attribute($name,$values,$server_id,$source);
+			return new PLAAttribute($name,$values,$server_id,$source);
 		}
 	}
 
