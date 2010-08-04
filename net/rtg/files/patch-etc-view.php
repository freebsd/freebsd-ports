--- etc/view.php.orig	2010-07-04 03:55:12.757175355 +0100
+++ etc/view.php	2010-07-04 03:59:40.479683639 +0100
@@ -95,19 +95,22 @@
 
       $bt = $et - (60*60*24);
       print "<B>Day View:</B><BR>\n";
-      print "<IMG SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\">\n";
+      print "<IMG SRC=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes";
+      print "&title=" . urlencode("$router: $name ($description)") . "&t1_name=" . urlencode("Input Octets") . "&t2_name=" . urlencode("Output Octets") . "\">\n";
       print "<BR><B>$router: $name ($description)</B>\n";
       print "<BR><HR>\n";
 
       $bt = $et - (60*60*24*7);
       print "<B>Week View:</B><BR>\n";
-      print "<IMG SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\">\n";
+      print "<IMG SRC=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes";
+      print "&title=" . urlencode("$router: $name ($description)") . "&t1_name=" . urlencode("Input Octets") . "&t2_name=" . urlencode("Output Octets") . "\">\n";
       print "<BR><B>$router: $name ($description)</B>\n";
       print "<BR><HR>\n";
 
       $bt = $et - (60*60*24*30);
       print "<B>Month View:</B><BR>\n";
-      print "<IMG SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\">\n";
+      print "<IMG SRC=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes";
+      print "&title=" . urlencode("$router: $name ($description)") . "&t1_name=" . urlencode("Input Octets") . "&t2_name=" . urlencode("Output Octets") . "\">\n";
       print "<BR><B>$router: $name ($description)</B>\n";
       print "<BR><BR>\n";
     }
@@ -134,7 +137,10 @@
 	$desc[$selectRow->id] = $selectRow->description;
 	$iid = $selectRow->id;
 	print "<TD><A HREF=\"$PHP_SELF?rid=$rid&iid=$iid\">\n";
-	print "<IMG HEIGHT=\"135\" WIDTH=\"500\" SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\" BORDER=\"0\">\n";
+	print "<IMG HEIGHT=\"135\" WIDTH=\"500\" SRC=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid;
+	print "&title=" . urlencode("$router: " . $selectRow->name . " (" . $selectRow->description . ")");
+	print "&t1_name=" . urlencode("Input Octets") . "&t2_name=" . urlencode("Output Octets");
+	print "&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\" BORDER=\"0\">\n";
 	print "</A><BR>\n";
         print "<B>$selectRow->name ($selectRow->description)</B>\n";
         if ($even) {
