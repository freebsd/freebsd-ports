--- ./share/pnp/include/fpdi_pdf_parser.php.orig	2010-05-29 23:27:44.000000000 +0200
+++ ./share/pnp/include/fpdi_pdf_parser.php	2010-05-29 23:27:44.000000000 +0200
@@ -242,7 +242,7 @@
                     if (preg_match("/^\/[a-z85]*$/i", $_filter[1], $filterName) && @include_once('decoders'.$_filter[1].'.php')) {
                         $filterName = substr($_filter[1],1);
                         if (class_exists($filterName)) {
-    	                	$decoder =& new $filterName($this->fpdi);
+    	                	$decoder = new $filterName($this->fpdi);
     	                    $stream = $decoder->decode(trim($stream));
                         } else {
                         	$this->fpdi->error(sprintf("Unsupported Filter: %s",$_filter[1]));
