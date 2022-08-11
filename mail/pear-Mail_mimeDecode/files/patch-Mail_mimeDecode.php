--- Mail/mimeDecode.php.orig	2016-08-29 03:04:25 UTC
+++ Mail/mimeDecode.php
@@ -834,7 +834,7 @@ class Mail_mimeDecode extends PEAR
 
         // Replace encoded characters
 		 
-        $cb = create_function('$matches',  ' return chr(hexdec($matches[0]));');
+        $cb = function(array $matches)  { return chr(hexdec($matches[0])); };
          
         $input = preg_replace_callback( '/=([a-f0-9]{2})/i', $cb, $input);
 
