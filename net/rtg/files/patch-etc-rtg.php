--- etc/rtg.php.orig	2010-07-04 03:49:22.836351752 +0100
+++ etc/rtg.php	2010-07-04 03:54:55.955519331 +0100
@@ -171,6 +171,9 @@
   #}
   #else {
     $args = "t1=ifInOctets_$rid&t2=ifOutOctets_$rid&begin=$bt&end=$et&units=bits/s&factor=8";
+    $args .= "&title=" . urlencode($selectRow->description);
+    $args .= "&t1_name=" . urlencode("Input Octets");
+    $args .= "&t2_name=" . urlencode("Output Octets");
     foreach ($iid as $value) {
       $args="$args&iid=$value";
     }
@@ -181,8 +184,11 @@
     if ($borderb) $args = "$args&borderb=$borderb";
     if ($aggr) $args = "$args&aggr=yes";
     if ($percentile) $args = "$args&percentile=$nth";
-    print "<IMG SRC=rtgplot.cgi?$args><BR>\n";
+    print "<IMG SRC=/cgi-bin/rtgplot.cgi?$args><BR>\n";
     $args = "t1=ifInUcastPkts_$rid&t2=ifOutUcastPkts_$rid&begin=$bt&end=$et&units=pkts/s";
+    $args .= "&title=" . urlencode($selectRow->description);
+    $args .= "&t1_name=" . urlencode("Input Packets");
+    $args .= "&t2_name=" . urlencode("Output Packets");
     foreach ($iid as $value) {
       $args="$args&iid=$value";
     }
@@ -192,9 +198,13 @@
     if ($borderb) $args = "$args&borderb=$borderb";
     if ($aggr) $args = "$args&aggr=yes";
     if ($percentile) $args = "$args&percentile=$nth";
-    print "<IMG SRC=rtgplot.cgi?$args><BR>\n";
+    print "<IMG SRC=/cgi-bin/rtgplot.cgi?$args><BR>\n";
     if ($errors) 
-       print "<IMG SRC=rtgplot.cgi?t1=ifInErrors_$rid&begin=$bt&end=$et&units=errors&impulses=yes>\n";
+    {
+       print "<IMG SRC=/cgi-bin/rtgplot.cgi?t1=ifInErrors_$rid&begin=$bt&end=$et&units=errors&impulses=yes";
+       print "&title=" . urlencode($selectRow->description);
+       print "&t1_name=" . urlencode("Errors") . ">\n";
+    }
 #  }
 } 
 
