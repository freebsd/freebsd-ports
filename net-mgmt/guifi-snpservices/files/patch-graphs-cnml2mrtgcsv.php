--- graphs/cnml2mrtgcsv.php.orig	2014-04-10 12:35:09.000000000 +0000
+++ graphs/cnml2mrtgcsv.php	2014-04-10 12:35:19.000000000 +0000
@@ -267,7 +267,7 @@
 // Opening CNML source
 $cnml = new DOMDocument;
 $cnml->preserveWhiteSpace = false;
-$cnml->Load('../data/guifi.cnml');
+$cnml->Load('/var/tmp/snpservices/data/guifi.cnml');
 $time_s = microtime(true);
 //print "# file guifi.cnml loaded".($time_s - $time_start)."\n";
 
