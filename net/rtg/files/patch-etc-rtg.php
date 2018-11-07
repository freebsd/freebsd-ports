--- etc/rtg.php.orig	2003-09-24 20:42:03 UTC
+++ etc/rtg.php
@@ -4,10 +4,8 @@
   print "<HTML>\n<!-- RTG Version $VERSION -->\n<HEAD>\n";
 
   /* Connect to RTG MySQL Database */
-  $dbc=@mysql_connect ($host, $user, $pass) or
-  $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or 
+  $dbc=@mysqli_connect ($host, $user, $pass, $db) or
      die ("MySQL Connection Failed, Check Configuration.");
-  mysql_select_db($db,$dbc);
 
  if ($PHP_SELF == "") {
    $PHP_SELF = "rtg.php";
@@ -37,17 +35,17 @@
   # Determine router, interface names as necessary
   if ($rid && $iid) {
     $selectQuery="SELECT a.name, a.description, a.speed, b.name AS router FROM interface a, router b WHERE a.rid=b.rid AND a.rid=$rid AND a.id=$iid[0]";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $selectRow=mysql_fetch_object($selectResult);
-    $interfaces = mysql_num_rows($selectResult);
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    $selectRow=mysqli_fetch_object($selectResult);
+    $interfaces = mysqli_num_rows($selectResult);
     $name = $selectRow->name;
     $description = $selectRow->description;
     $speed = ($selectRow->speed)/1000000;
     $router = $selectRow->router;
   } else if ($rid && !$iid) {
     $selectQuery="SELECT name AS router from router where rid=$rid";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $selectRow=mysql_fetch_object($selectResult);
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    $selectRow=mysqli_fetch_object($selectResult);
     $router = $selectRow->router;
   }
 
@@ -71,8 +69,8 @@ echo "<FORM ACTION=\"$PHP_SELF\" METHOD=
 if (!$rid && !$iid) {
  echo "<SELECT NAME=\"rid\" SIZE=10>\n";
  $selectQuery="SELECT DISTINCT name, rid FROM router ORDER BY name";
- $selectResult=mysql_query($selectQuery, $dbc);
- while ($selectRow=mysql_fetch_object($selectResult)){
+ $selectResult=mysqli_query($dbc, $selectQuery);
+ while ($selectRow=mysqli_fetch_object($selectResult)){
     echo "<OPTION VALUE=\"$selectRow->rid\">$selectRow->name\n";
  }
  echo "</SELECT>\n";
@@ -91,8 +89,8 @@ if ($rid && !$iid) {
 
   echo "<SELECT MULTIPLE NAME=\"iid[]\" SIZE=10>\n"; 
   $selectQuery="SELECT id, name, description FROM interface WHERE rid=$rid ORDER BY name";
-  $selectResult=mysql_query($selectQuery, $dbc);
-  while ($selectRow=mysql_fetch_object($selectResult)){
+  $selectResult=mysqli_query($dbc, $selectQuery);
+  while ($selectRow=mysqli_fetch_object($selectResult)){
      echo "<OPTION VALUE=\"$selectRow->id\">$selectRow->name ($selectRow->description)\n";
   }
   echo "</SELECT>\n";
@@ -152,8 +150,8 @@ if (($bt || $smonth) && $iid) { 
   $range="$range AND id=$iid[0]";
 
   $selectQuery="SELECT description, name, speed FROM interface WHERE rid=$rid AND id=$iid[0]";
-  $selectResult=mysql_query($selectQuery, $dbc);
-  $selectRow=mysql_fetch_object($selectResult);
+  $selectResult=mysqli_query($dbc, $selectQuery);
+  $selectRow=mysqli_fetch_object($selectResult);
   echo "<TABLE BORDER=0>\n";
   echo "<TD><I>Device</I>:</TD><TD>$router ($rid)</TD><TR>\n";
   echo "<TD><I>Interface</I>:</TD><TD>$selectRow->name ($iid[0])</TD><TR>\n";
@@ -165,12 +163,15 @@ if (($bt || $smonth) && $iid) { 
   echo "<P>\n";
  
   #$selectQuery="SELECT DISTINCT id FROM ifInOctets_$rid WHERE $range";
-  #$selectResult=mysql_query($selectQuery, $dbc);
-  #if (mysql_num_rows($selectResult) <= 0) {
+  #$selectResult=mysqli_query($dbc, $selectQuery);
+  #if (mysqli_num_rows($selectResult) <= 0) {
   #   print "<BR>No Data Found on Interface for Given Range.<BR>\n";
   #}
   #else {
     $args = "t1=ifInOctets_$rid&t2=ifOutOctets_$rid&begin=$bt&end=$et&units=bits/s&factor=8";
+    $args .= "&title=" . urlencode($selectRow->description);
+    $args .= "&t1_name=" . urlencode("Input Octets");
+    $args .= "&t2_name=" . urlencode("Output Octets");
     foreach ($iid as $value) {
       $args="$args&iid=$value";
     }
@@ -181,8 +182,11 @@ if (($bt || $smonth) && $iid) { 
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
@@ -192,13 +196,17 @@ if (($bt || $smonth) && $iid) { 
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
 
-mysql_close($dbc);
+mysqli_close($dbc);
 ?>
 
 <P>
