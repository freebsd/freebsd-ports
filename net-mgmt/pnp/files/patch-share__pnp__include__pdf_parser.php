--- ./share/pnp/include/pdf_parser.php.orig	2010-05-29 23:27:44.000000000 +0200
+++ ./share/pnp/include/pdf_parser.php	2010-05-29 23:31:23.000000000 +0200
@@ -91,7 +91,7 @@
 
         $this->getPDFVersion();
 
-        $this->c =& new pdf_context($this->f);
+        $this->c = new pdf_context($this->f);
         // Read xref-Data
         $this->pdf_read_xref($this->xref, $this->pdf_find_xref());
 
@@ -257,7 +257,7 @@
             	fseek($this->f, $o_pos+strlen($m[1]));
     		}
     		
-			$c =&  new pdf_context($this->f);
+			$c = new pdf_context($this->f);
     	    $trailer = $this->pdf_read_value($c);
     	    
     	    if (isset($trailer[1]['/Prev'])) {
@@ -423,7 +423,7 @@
 		        	$e++;
 		        
 		        if ($this->actual_obj[1][1]['/Length'][0] == PDF_TYPE_OBJREF) {
-		        	$tmp_c =& new pdf_context($this->f);
+		        	$tmp_c = new pdf_context($this->f);
 		        	$tmp_length = $this->pdf_resolve_object($tmp_c,$this->actual_obj[1][1]['/Length']);
 		        	$length = $tmp_length[1][1];
 		        } else {
