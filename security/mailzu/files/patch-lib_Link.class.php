--- lib/Link.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/Link.class.php
@@ -29,7 +29,7 @@ class Link {
 	* @param string $text_on_over text to display in status bar onmouseover
 	* @param string $on_over javascript to call onmouseover
 	*/
-	function Link($url=null, $text=null, $class=null, $style=null, $text_on_over=null) {
+	function __construct($url=null, $text=null, $class=null, $style=null, $text_on_over=null) {
 		$this->url = $url;
 		$this->text = $text;
 		$this->_class = $class;
