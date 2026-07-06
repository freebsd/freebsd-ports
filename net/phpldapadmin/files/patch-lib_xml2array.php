--- lib/xml2array.php.orig	2026-06-05 14:24:55 UTC
+++ lib/xml2array.php
@@ -51,7 +51,7 @@ class xml2array {
 				xml_get_current_line_number($this->resParser),
 				$filename));
 
-		xml_parser_free($this->resParser);
+		// xml_parser_free($this->resParser);
 
 		$output = array();
 		foreach ($this->arrOutput as $key => $values)
