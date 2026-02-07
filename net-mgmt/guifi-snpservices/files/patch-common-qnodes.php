--- common/qnodes.php.orig	2014-04-10 12:44:55.000000000 +0000
+++ common/qnodes.php	2014-04-10 12:45:28.000000000 +0000
@@ -19,7 +19,7 @@
 // Opening CNML source
 $doc = new DOMDocument;
 $doc->preserveWhiteSpace = false;
-$doc->Load('../data/guifi.cnml');
+$doc->Load('/var/tmp/snpservices/data/guifi.cnml');
 
 // building the xpath query for requested nodes
 $xpath = new DOMXPath($doc);
