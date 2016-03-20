--- ./graphs/mrtgcsv2mrtgcfg.php.orig	2015-06-16 21:14:01.000000000 +0100
+++ ./graphs/mrtgcsv2mrtgcfg.php	2016-01-31 18:18:04.779135280 +0000
@@ -1,20 +1,20 @@
 <?php
 
-if (file_exists("../common/config.php")) {
-   include_once("../common/config.php");
+if (file_exists(dirname(__FILE__)."../common/config.php")) {
+   include_once(dirname(__FILE__)."../common/config.php");
 } else {
-  include_once("../common/config.php.template");
+  include_once(dirname(__FILE__)."/../common/config.php.template");
 }
 
 function mrtgcfg_from_mrtgcsv($rrdtool_header,$rrdimg_path,$rrddb_path,$mrtg_traffic_template,$mrtg_ping_template) {
 
   if (!file_exists('/tmp/blacklist.ips'))
-    system('/bin/touch /tmp/blacklist.ips');
+    system('/usr/bin/touch /tmp/blacklist.ips');
 
-    system('/bin/grep -vf /tmp/blacklist.ips /tmp/mrtg.csv > /tmp/mrtg.blacklisted.csv');
+    system('/usr/bin/grep -vf /tmp/blacklist.ips /tmp/mrtg.csv > /tmp/mrtg.blacklisted.csv');
 
 $hf = @fopen('/tmp/mrtg.blacklisted.csv','r');
-$cf = @fopen('../data/mrtg.cfg','w+');
+$cf = @fopen('/var/tmp/snpservices/data/mrtg.cfg','w+');
 
 fputs($cf,sprintf($rrdtool_header,$rrdimg_path,$rrdimg_path,$rrddb_path,$rrddb_path));
 
@@ -96,8 +96,8 @@
 if ($argv[1]=="CACHE") {
   if (file_exists('/tmp/blacklist.ips')) { 
     $blacklist_time = filemtime('/tmp/blacklist.ips');
-    if (file_exists('../data/mrtg.cfg')) {
-       $mrtg_time = filemtime('../data/mrtg.cfg');
+    if (file_exists('/var/tmp/snpservices/data/mrtg.cfg')) {
+       $mrtg_time = filemtime('/var/tmp/snpservices/data/mrtg.cfg');
     } else {
        $mrtg_time = 0;
        echo "No mrtg.cfg file present, refreshing...\n";
