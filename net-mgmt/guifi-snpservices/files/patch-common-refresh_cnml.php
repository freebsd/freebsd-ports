--- common/refresh_cnml.php.orig	2014-04-10 12:41:40.000000000 +0000
+++ common/refresh_cnml.php	2014-04-10 12:43:16.000000000 +0000
@@ -27,14 +27,14 @@
   echo "Getting CNML file\n";
   $hcnml = @fopen($SNPDataServer_url."/guifi/cnml/".$rootZone."/detail", "r")
     or die ('Error redaing CNML source\n');
-  $wcnml = @fopen("../data/guifi.cnml.tmp", "w");
+  $wcnml = @fopen("/var/tmp/snpservices/data/guifi.cnml.tmp", "w");
   while (!feof($hcnml)) {
     $buffer = fgets($hcnml, 4096);
     fwrite($wcnml,$buffer);
   }
   fclose($hcnml);
   fclose($wcnml);
-  exec ("/bin/cp ../data/guifi.cnml.tmp ../data/guifi.cnml");
+  exec ("/bin/cp /var/tmp/snpservices/data/guifi.cnml.tmp /var/tmp/snpservices/data/guifi.cnml");
 
   $hlast= @fopen("/tmp/last_update.cnml", "w") or die('Error!');
   fwrite($hlast,$last_now);
