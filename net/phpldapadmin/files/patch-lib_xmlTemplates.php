--- lib/xmlTemplates.php.orig	2021-12-12 02:35:51 UTC
+++ lib/xmlTemplates.php
@@ -85,7 +85,7 @@ abstract class xmlTemplates {
 					$filename = sprintf('%s/%s',$dir,$file);
 
 					if (! in_array($filename,$this->getTemplateFiles())) {
-						$templatename = preg_replace('/.xml$/','',$file);
+						$templatename = preg_replace('/.xml$/','',is_null($file)? "":$file);
 	
 						$this->templates[$index] = new $class['name']($this->server_id,$templatename,$filename,$type,$index);
 						$index++;
@@ -128,7 +128,7 @@ abstract class xmlTemplates {
 					$filename = sprintf('%s/%s',$dir,$file);
 
 					# Store the template
-					$templatename = preg_replace('/.xml$/','',$file);
+					$templatename = preg_replace('/.xml$/','',is_null($file)? "":$file);
 					$this->templates[$counter] = new $class['name']($this->server_id,$templatename,$filename,$type,$counter);
 					$counter++;
 				}
@@ -304,7 +304,7 @@ abstract class xmlTemplate {
 			debug_log('Entered (%%)',5,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		foreach ($this->attributes as $index => $attribute)
-			if (strtolower($attr) == $attribute->getName() || in_array(strtolower($attr),$attribute->getAliases()))
+			if (strtolower((string) $attr) == $attribute->getName() || in_array(strtolower($attr),$attribute->getAliases()))
 				return $index;
 
 		return null;
@@ -343,7 +343,7 @@ abstract class xmlTemplate {
 			debug_log('Entered (%%)',5,1,__FILE__,__LINE__,__METHOD__,$fargs,$this->name);
 
 		if ($lower)
-			return strtolower($this->name);
+			return strtolower((string) $this->name);
 		else
 			return $this->name;
 	}
@@ -482,7 +482,7 @@ abstract class xmlTemplate {
 			debug_log('Entered (%%)',5,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 		foreach ($this->attributes as $attribute)
-			if (($attribute->getName() == strtolower($name)) || in_array(strtolower($name),$attribute->getAliases()))
+			if (($attribute->getName() == strtolower((string) $name)) || in_array(strtolower($name),$attribute->getAliases()))
 				return $attribute;
 
 		return null;
