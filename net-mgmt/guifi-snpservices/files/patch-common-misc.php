--- common/misc.php.orig	2014-04-10 14:05:20.000000000 +0000
+++ common/misc.php	2014-04-10 14:05:45.000000000 +0000
@@ -177,7 +177,7 @@
   foreach ($an as $nc) {
   	$try = 0;
   	$xml = false;
-    $fn = $prefix.'tmp/'.$nc.'.cnml';
+    $fn = $prefix.'/var/tmp/snpservices/tmp/'.$nc.'.cnml';
     do {
 //  	  print " Processing $nc try $try cache: $waitcache\n<br>";
   	  if (file_exists($fn)) {
@@ -232,7 +232,7 @@
     if ($xml) {
     $xpnxml = $xml->xpath('//node');
     foreach ($xpnxml as $nxml) {
-      $fn = $prefix.'tmp/'.$nxml->attributes()->id.'.cnml';    	
+      $fn = $prefix.'/var/tmp/snpservices/tmp/'.$nxml->attributes()->id.'.cnml';    	
       $wcnml = @fopen($fn, "w+") or die("\n<br>Error caching XML, can't write $fn\n");
       fwrite($wcnml,'<cnml>'.$nxml->asXML().'</cnml>');
       fclose($wcnml);
