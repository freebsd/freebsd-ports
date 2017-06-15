--- etc/view.php.orig	2003-09-26 15:58:34 UTC
+++ etc/view.php
@@ -11,10 +11,8 @@
   print "<HTML>\n<!-- RTG Version $VERSION -->\n<HEAD>\n";
 
   /* Connect to RTG MySQL Database */
-  $dbc=@mysql_connect ($host, $user, $pass) or
-  $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or 
+  $dbc=@mysqli_connect ($host, $user, $pass, $db) or
      die ("MySQL Connection Failed, Check Configuration.");
-  mysql_select_db($db,$dbc);
 
   # Global variables off by default in newer versions of PHP
   if (!$PHP_SELF) {
@@ -26,17 +24,17 @@
   # Determine router, interface names as necessary
   if ($rid && $iid) {
     $selectQuery="SELECT a.name, a.description, a.speed, b.name AS router FROM interface a, router b WHERE a.rid=b.rid AND a.rid=$rid AND a.id=$iid";
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
 
@@ -68,12 +66,12 @@
  if (!$rid) {
     print "Monitored Devices: <P>\n";
     $selectQuery="SELECT rid, name FROM router";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    if (mysql_num_rows($selectResult) <= 0) 
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    if (mysqli_num_rows($selectResult) <= 0) 
       print "<BR>No Routers Found.<BR>\n";
     else {
       print "<UL>\n";
-      while ($selectRow=mysql_fetch_object($selectResult)){
+      while ($selectRow=mysqli_fetch_object($selectResult)){
         print "<LI><A HREF=\"$PHP_SELF?rid=$selectRow->rid\">";
         print "$selectRow->name</A><BR>\n";
       }
@@ -95,19 +93,22 @@
 
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
@@ -116,8 +117,8 @@
 
  if ($rid && !$iid) {
     $selectQuery="SELECT id, name, description FROM interface WHERE rid=$rid";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $interfaces = mysql_num_rows($selectResult);
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    $interfaces = mysqli_num_rows($selectResult);
     if ($interfaces <= 0) 
       print "<BR>No Interfaces Found for Router $router (ID: $rid).<BR>\n";
     else {
@@ -129,12 +130,15 @@
       print gmdate('D, d M Y H:i:s \G\M\T', time())."\n";
       print "</TABLE><HR>\n";
       print "<TABLE BORDER=\"0\" CELLPADDING=\"0\" CELLSPACING=\"10\">\n";
-      while ($selectRow=mysql_fetch_object($selectResult)){
+      while ($selectRow=mysqli_fetch_object($selectResult)){
         $ids[$selectRow->id] = $selectRow->name; 
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
@@ -148,7 +152,7 @@
     print "<INPUT TYPE=\"SUBMIT\" VALUE=\"Back to Main\">\n";
   }
 
-  if ($dbc) mysql_close($dbc);
+  if ($dbc) mysqli_close($dbc);
   echo "</FORM>\n";
 ?>
 
