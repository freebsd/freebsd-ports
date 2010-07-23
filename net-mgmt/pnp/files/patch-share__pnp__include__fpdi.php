--- ./share/pnp/include/fpdi.php.orig	2010-05-29 23:27:44.000000000 +0200
+++ ./share/pnp/include/fpdi.php	2010-05-29 23:27:44.000000000 +0200
@@ -93,7 +93,7 @@
         $fn =& $this->current_filename;
 
         if (!isset($this->parsers[$fn]))
-            $this->parsers[$fn] =& new fpdi_pdf_parser($fn,$this);
+            $this->parsers[$fn] = new fpdi_pdf_parser($fn,$this);
         $this->current_parser =& $this->parsers[$fn];
         
         return $this->parsers[$fn]->getPageCount();
