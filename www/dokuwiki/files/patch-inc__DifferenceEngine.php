--- ./inc/DifferenceEngine.php.orig	2010-11-08 00:43:03.000000000 +0800
+++ ./inc/DifferenceEngine.php	2010-11-09 02:54:41.000000000 +0800
@@ -896,7 +896,7 @@
     }
 
     function _split($lines) {
-            if (!preg_match_all('/ ( [^\S\n]+ | [0-9_A-Za-z\x80-\xff]+ | . ) (?: (?!< \n) [^\S\n])? /xs',
+            if (!preg_match_all('/ ( [^\S\n]+ | [0-9_A-Za-z\x80-\xff]+ | . ) (?: (?!< \n) [^\S\n])? /xsu',
                     implode("\n", $lines),
                     $m)) {
             return array(array(''), array(''));
