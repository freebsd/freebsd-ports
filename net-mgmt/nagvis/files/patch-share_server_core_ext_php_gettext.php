--- share/server/core/ext/php-gettext-1.0.9/gettext.php.orig	2017-12-21 20:52:04.548840000 +0100
+++ share/server/core/ext/php-gettext-1.0.9/gettext.php	2017-12-21 20:52:26.904652000 +0100
@@ -98,7 +98,7 @@
    * @param object Reader the StreamReader object
    * @param boolean enable_cache Enable or disable caching of strings (default on)
    */
-  function gettext_reader($Reader, $enable_cache = true) {
+  function __construct($Reader, $enable_cache = true) {
     // If there isn't a StreamReader, turn on short circuit mode.
     if (! $Reader || isset($Reader->error) ) {
       $this->short_circuit = true;
--- share/server/core/ext/php-gettext-1.0.9/streams.php.orig	2017-12-21 20:52:12.507752000 +0100
+++ share/server/core/ext/php-gettext-1.0.9/streams.php	2017-12-21 20:53:08.533635000 +0100
@@ -49,7 +49,7 @@
   var $_pos;
   var $_str;
 
-  function StringReader($str='') {
+  function __construct($str='') {
     $this->_str = $str;
     $this->_pos = 0;
   }
@@ -86,7 +86,7 @@
   var $_fd;
   var $_length;
 
-  function FileReader($filename) {
+  function __construct($filename) {
     if (file_exists($filename)) {
 
       $this->_length=filesize($filename);
@@ -143,7 +143,7 @@
 // Preloads entire file in memory first, then creates a StringReader
 // over it (it assumes knowledge of StringReader internals)
 class CachedFileReader extends StringReader {
-  function CachedFileReader($filename) {
+  function __construct($filename) {
     if (file_exists($filename)) {
 
       $length=filesize($filename);
