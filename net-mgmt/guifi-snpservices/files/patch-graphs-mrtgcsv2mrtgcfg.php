--- graphs/mrtgcsv2mrtgcfg.php.orig	2014-02-21 15:53:13.000000000 +0000
+++ graphs/mrtgcsv2mrtgcfg.php	2014-04-10 12:35:33.000000000 +0000
@@ -1,9 +1,9 @@
 <?php
 
-if (file_exists("../common/config.php")) {
-   include_once("../common/config.php");
+if (file_exists(dirname(__FILE__)."../common/config.php")) {
+   include_once(dirname(__FILE__)."../common/config.php");
 } else {
-  include_once("../common/config.php.template");
+  include_once(dirname(__FILE__)."/../common/config.php.template");
 }
 
 $now = time();
@@ -57,7 +57,7 @@
 print date('Y/m/d H:i:s')."\n";
 
 $hf = @fopen($MRTGConfigSource,"r") or die('Error reading MRTG csv input\n"');
-$cf = @fopen('../data/mrtg.cfg','w+');
+$cf = @fopen('/var/tmp/snpservices/data/mrtg.cfg','w+');
 
 fputs($cf,sprintf($rrdtool_header,$rrdimg_path,$rrdimg_path,$rrddb_path,$rrddb_path));
 
