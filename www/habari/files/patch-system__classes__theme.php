--- system/classes/theme.php.orig	2011-12-13 05:22:28.000000000 +0000
+++ system/classes/theme.php	2012-06-18 10:24:39.000000000 +0100
@@ -90,7 +90,7 @@
 	public function info()
 	{
 
-		$xml_file = $this->theme_dir . '/theme.xml';
+		$xml_file = end( $this->theme_dir ) . '/theme.xml';
 		if(!file_exists($xml_file)) {
 			return new SimpleXMLElement('<?xml version="1.0" encoding="utf-8" ?>
 <pluggable type="theme">
