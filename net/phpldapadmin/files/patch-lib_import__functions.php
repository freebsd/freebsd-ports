--- lib/import_functions.php.orig	2025-05-26 10:22:02 UTC
+++ lib/import_functions.php
@@ -147,6 +147,8 @@ class ImportLDIF extends Import {
 class ImportLDIF extends Import {
 	private $_currentLineNumber = 0;
 	private $_currentLine = '';
+	private $_currentDnLine = '';
+	private $dnLineNumber = 0;
 	private $template;
 	public $error = array();
 
