--- lib/xml2array.php.orig	2021-12-12 02:35:51 UTC
+++ lib/xml2array.php
@@ -59,7 +59,7 @@ class xml2array {
 	}
 
 	private function tagOpen($parser,$name,$attrs) {
-		$name = strtolower($name);
+		$name = strtolower((string) $name);
 
 		if (isset($this->stack_ref[$name])) {
 			if (! isset($this->stack_ref[$name][0])) {
@@ -86,7 +86,7 @@ class xml2array {
 	}
 
 	private function tagData($parser,$tagData) {
-		if (trim($tagData) != '') {
+		if (trim((string) $tagData) != '') {
 
 			if (isset($this->stack_ref['#text']))
 				$this->stack_ref['#text'] .= $tagData;
