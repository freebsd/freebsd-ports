--- lib/xml2array.php.orig	2024-01-10 22:23:54 UTC
+++ lib/xml2array.php
@@ -20,6 +20,7 @@ class xml2array {
 	var $arrOutput = array();
 	var $resParser;
 	var $strXmlData;
+	// var $parser;
 
 	private function push_pos(&$pos) {
 		$this->stack[count($this->stack)] = &$pos;
@@ -33,10 +34,12 @@ class xml2array {
 
 	public function parseXML($strInputXML,$filename) {
 		$this->resParser = xml_parser_create();
-		xml_set_object($this->resParser,$this);
-		xml_set_element_handler($this->resParser,'tagOpen','tagClosed');
+		// xml_set_object($this->resParser,$this);
+		// xml_set_element_handler($this->resParser,'tagOpen','tagClosed');
 
-		xml_set_character_data_handler($this->resParser,'tagData');
+		// xml_set_character_data_handler($this->resParser,'tagData');
+		xml_set_element_handler($this->resParser, array( $this, 'tagOpen' ), array( $this, 'tagClosed' ) );
+		xml_set_character_data_handler( $this->resParser, array( $this, 'tagData' ));
 
 		$this->push_pos($this->arrOutput);
 
