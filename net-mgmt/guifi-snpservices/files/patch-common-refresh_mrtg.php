--- common/refresh_mrtg.php.orig	2014-04-10 12:44:08.000000000 +0000
+++ common/refresh_mrtg.php	2014-04-10 12:44:27.000000000 +0000
@@ -29,7 +29,7 @@
 
   echo "Getting MRTG CSV file\n";
   $hcnml = @fopen($MRTGConfigSource, "r");
-  $wcnml = @fopen("../data/guifi_mrtg.csv", "w");
+  $wcnml = @fopen("/var/tmp/snpservices/data/guifi_mrtg.csv", "w");
   while (!feof($hcnml)) {
        $buffer = fgets($hcnml, 4096);
        fwrite($wcnml,$buffer);
