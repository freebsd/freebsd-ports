--- lib/htmlfilter.php.orig	2007-06-14 19:00:15 UTC
+++ lib/htmlfilter.php
@@ -106,7 +106,7 @@ function casenormalize(&$val){
 function skipspace($body, $offset){
     $me = 'skipspace';
     preg_match('/^(\s*)/s', substr($body, $offset), $matches);
-    if (sizeof($matches{1})){
+    if (is_array($matches{1}) && sizeof($matches{1})){
         $count = strlen($matches{1});
         spew("$me: skipped $count chars\n");
         $offset += $count;
