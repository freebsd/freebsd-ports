--- lib/xml2array.php.orig	2024-01-10 22:23:54 UTC
+++ lib/xml2array.php
@@ -33,10 +33,9 @@ class xml2array {
 
 	public function parseXML($strInputXML,$filename) {
 		$this->resParser = xml_parser_create();
-		xml_set_object($this->resParser,$this);
-		xml_set_element_handler($this->resParser,'tagOpen','tagClosed');
+		xml_set_element_handler($this->resParser,[$this, 'tagOpen'],[$this, 'tagClosed']);
 
-		xml_set_character_data_handler($this->resParser,'tagData');
+		xml_set_character_data_handler($this->resParser,[$this, 'tagData']);
 
 		$this->push_pos($this->arrOutput);
 
@@ -48,7 +47,7 @@ class xml2array {
 				xml_get_current_line_number($this->resParser),
 				$filename));
 
-		xml_parser_free($this->resParser);
+		// xml_parser_free($this->resParser);
 
 		$output = array();
 		foreach ($this->arrOutput as $key => $values)
