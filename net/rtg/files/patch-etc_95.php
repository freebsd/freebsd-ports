--- etc/95.php.orig	2003-09-24 20:40:57 UTC
+++ etc/95.php
@@ -1,41 +1,37 @@
 <?php
   include('./common.php');
 
-  print "<HTML>\n<!-- RTG Version $VERSION -->\n<HEAD>\n";
+  print "<html>\n<!-- RTG Version $VERSION -->\n<head>\n";
 
   /* Connect to RTG MySQL Database */
-  $dbc=@mysql_connect ($host, $user, $pass) or
-  $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or 
+  $dbc=@mysqli_connect ($host, $user, $pass, $db) or
      die ("MySQL Connection Failed, Check Configuration.");
-  mysql_select_db($db,$dbc);
 
-  if ($PHP_SELF == "") {
+  if (!isset($PHP_SELF) || ($PHP_SELF == "")) {
     $PHP_SELF = "95.php";
-    $customer = $_GET['customer'];
-    $syear = $_GET['syear'];
-    $eyear = $_GET['eyear'];
-    $smonth = $_GET['smonth'];
-    $emonth = $_GET['emonth'];
-    $sday = $_GET['sday'];
-    $eday = $_GET['eday'];
-    $shour = $_GET['shour'];
-    $ehour = $_GET['ehour'];
-    $smin = $_GET['smin'];
-    $emin = $_GET['emin'];
-    $debug = $_GET['debug'];
+    $customer = isset($_GET['customer'])?$_GET['customer']:"";
+    $syear = isset($_GET['syear'])?$_GET['syear']:"";
+    $eyear = isset($_GET['eyear'])?$_GET['eyear']:"";
+    $smonth = isset($_GET['smonth'])?$_GET['smonth']:"";
+    $emonth = isset($_GET['emonth'])?$_GET['emonth']:"";
+    $sday = isset($_GET['sday'])?$_GET['sday']:"";
+    $eday = isset($_GET['eday'])?$_GET['eday']:"";
+    $shour = isset($_GET['shour'])?$_GET['shour']:"";
+    $ehour = isset($_GET['ehour'])?$_GET['ehour']:"";
+    $smin = isset($_GET['smin'])?$_GET['smin']:"";
+    $emin = isset($_GET['emin'])?$_GET['emin']:"";
+    $debug = isset($_GET['debug'])?$_GET['debug']:"";
   }
 
- print "<TITLE>RTG: ";
- if ($customer) print "$customer\n";
+ print "<title>RTG: ";
+ if ($customer != "") print "$customer\n";
 ?>
 
-</TITLE>
-</HEAD>
-<BODY BGCOLOR="ffffff">
-<A HREF="http://rtg.sourceforge.net" ALT="[RTG Home Page]">
-<IMG SRC="rtg.png" BORDER="0">
-</A>
-<P>
+</title>
+</head>
+<body bgcolor="ffffff">
+<a href="http://rtg.sourceforge.net"><img src="rtg.png" border="0" alt="[RTG Home Page]" /></a>
+<p>
 
 <?php
 function cmp($c1, $c2) {
@@ -50,8 +46,8 @@ function int_stats($statement, $dbc) {
   $max = $avg = $nintyfifth = 0;
   $rate = array();
 
-  $selectResult=mysql_query($statement, $dbc);
-  while ($selectRow=mysql_fetch_object($selectResult)){
+  $selectResult=mysqli_query($dbc, $statement);
+  while ($selectRow=mysqli_fetch_object($selectResult)){
     $counter = $selectRow->counter;
     $sample_secs = $selectRow->unixtime;
     $total += $counter;
@@ -83,132 +79,136 @@ function int_stats($statement, $dbc) {
 }
 ?>
 
-<HR>
-Report: 95th percentile<BR>
+<hr />
+Report: 95th percentile<br />
 
 <?php
-  echo "<FORM ACTION=\"$PHP_SELF\" METHOD=\"GET\">\n";
-  if (($bt || $smonth)) { 
-    $dbc=@mysql_connect ($host, $user, $pass) or
-    $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or die ("MySQL Connection Failed, Check Configuration.");
-    mysql_select_db($db,$dbc);
+  echo "<form action=\"$PHP_SELF\" method=\"get\">\n";
+  if (($bt != "") || ($smonth != "")) {
+    $dbc=@mysqli_connect ($host, $user, $pass, $db) or
+      die ("MySQL Connection Failed, Check Configuration.");
     /* Format into GNU date syntax */
     if ($bt == "") {
       $bt = strtotime("$syear-$smonth-$sday $shour:$smin:00");
       $et = strtotime("$eyear-$emonth-$eday $ehour:$emin:59");
     }
-    echo "Customer: $customer <BR>\n";
+    echo "Customer: $customer <br />\n";
     print strftime("Period: %m/%d/%Y %H:%M - ", $bt);
     print strftime("%m/%d/%Y %H:%M<P>\n", $et);
 
-    $range="dtime>FROM_UNIXTIME($bt) AND dtime<=FROM_UNIXTIME($et)";
+    $range="`dtime`>FROM_UNIXTIME(" . mysqli_real_escape_string($dbc, $bt) . 
+      ") AND `dtime`<=FROM_UNIXTIME(" . mysqli_real_escape_string($dbc, $et) . ")";
 
-    $selectQuery="SELECT id, name, description, rid FROM interface WHERE description LIKE \"%$customer%\"";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    if (mysql_num_rows($selectResult) <= 0) 
-      print "<BR>No Such Customer Found.<BR>\n";
+    $selectQuery="SELECT `id`, `name`, `description`, `rid` FROM `interface` WHERE " .
+      "`description` LIKE \"%" . mysqli_real_escape_string($dbc, $customer) . "%\"";
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    if (mysqli_num_rows($selectResult) <= 0) 
+      print "<br />No Such Customer Found.<br />\n";
     else {
-      while ($selectRow=mysql_fetch_object($selectResult)){
+      while ($selectRow=mysqli_fetch_object($selectResult)){
         $ids[$selectRow->id] = $selectRow->name; 
         $rids[$selectRow->id] = $selectRow->rid; 
 	$desc[$selectRow->id] = $selectRow->description;
       }
-      echo "<TABLE BORDER=\"1\">\n";
-      echo "<TR BGCOLOR=\"#E0E0E0\">\n";
-      echo "<TH COLSPAN=\"3\">Interface<TH COLSPAN=\"2\">Current Rate<TH COLSPAN=\"2\">Max Rate<TH COLSPAN=\"2\">95th %\n";
+      echo "<table border=\"1\">\n";
+      echo "<tr bgcolor=\"#E0E0E0\">\n";
+      echo "<th colspan=\"3\">Interface</th><th colspan=\"2\">Current Rate</th><th colspan=\"2\">Max Rate</th><th colspan=\"2\">95th %</th>\n";
       if ($debug) 
-        echo "<TH COLSPAN=\"2\">Samples<TH COLSPAN=\"2\">Ignore Top\n";
-      echo "<TR BGCOLOR=\"#E0E0E0\">\n";
-      echo "<TH>Name<TH>Description<TH>Router<TH>In (Mbps)<TH>Out (Mbps)<TH>In<TH>Out<TH>In<TH>Out\n";
+        echo "<th colspan=\"2\">Samples</th><th colspan=\"2\">Ignore Top</th>\n";
+      echo "</tr>\n";
+      echo "<tr bgcolor=\"#E0E0E0\">\n";
+      echo "<th>Name</th><th>Description</th><th>Router</th><th>In (Mbps)</th><th>Out (Mbps)</th><th>In</th><th>Out</th><th>In</th><th>Out</th>\n";
       if ($debug) 
-        echo "<TH>In<TH>Out<TH>In<TH>Out\n";
-      echo "<TR BGCOLOR=\"#ffffcc\">\n";
+        echo "<th>In</th><th>Out</th><th>In</th><th>Out</th>\n";
+      echo "</tr>\n";
+      echo "<tr bgcolor=\"#ffffcc\">\n";
       $yellow = 1;
       foreach($ids as $iid=>$name) {
 
-        $selectQuery="SELECT name FROM router WHERE rid=$rids[$iid]";
-        $selectResult=mysql_query($selectQuery, $dbc);
-        $selectRow=mysql_fetch_object($selectResult);
+        $selectQuery="SELECT `name` FROM `router` WHERE `rid`=$rids[$iid]";
+        $selectResult=mysqli_query($dbc, $selectQuery);
+        $selectRow=mysqli_fetch_object($selectResult);
 	$router = $selectRow->name;
 
         if ($yellow) $yellow = 0;
 	else $yellow = 1;
 
-        echo "<TD>$name<TD>$desc[$iid]<TD>$router";
+        echo "<td>$name</td><td>$desc[$iid]</td><td>$router</td>";
 
-        $selectQuery="SELECT counter, UNIX_TIMESTAMP(dtime) as unixtime, dtime from ifInOctets_$rids[$iid] WHERE $range AND id=$iid ORDER BY dtime";
+        $selectQuery="SELECT `counter`, UNIX_TIMESTAMP(`dtime`) AS `unixtime`, `dtime` FROM `ifInOctets_$rids[$iid]` WHERE $range AND `id`=$iid ORDER BY `dtime`";
         list ($intbytes_in, $maxin, $avgin, $nfin,$insamples,$inignore) = int_stats($selectQuery, $dbc);
 	$bytesin = round($intbytes_in/1000000);
 
-        $selectQuery="SELECT counter, UNIX_TIMESTAMP(dtime) as unixtime, dtime from ifOutOctets_$rids[$iid] WHERE $range AND id=$iid ORDER BY dtime";
+        $selectQuery="SELECT `counter`, UNIX_TIMESTAMP(`dtime`) AS `unixtime`, `dtime` FROM `ifOutOctets_$rids[$iid]` WHERE $range AND `id`=$iid ORDER BY `dtime`";
         list ($intbytes_out, $maxout, $avgout, $nfout,$outsamples,$outignore) = int_stats($selectQuery, $dbc);
 	$bytesout = round($intbytes_in/1000000);
 
-	printf("<TD ALIGN=\"right\">%2.2f", $avgin/1000000);
-	printf("<TD ALIGN=\"right\">%2.2f", $avgout/1000000);
-	printf("<TD ALIGN=\"right\">%2.2f", $maxin/1000000);
-	printf("<TD ALIGN=\"right\">%2.2f", $maxout/1000000);
-	printf("<TD ALIGN=\"right\">%2.2f", $nfin/1000000);
-	printf("<TD ALIGN=\"right\">%2.2f", $nfout/1000000);
+	printf("<td align=\"right\">%2.2f</td>", $avgin/1000000);
+	printf("<td align=\"right\">%2.2f</td>", $avgout/1000000);
+	printf("<td align=\"right\">%2.2f</td>", $maxin/1000000);
+	printf("<td align=\"right\">%2.2f</td>", $maxout/1000000);
+	printf("<td align=\"right\">%2.2f</td>", $nfin/1000000);
+	printf("<td align=\"right\">%2.2f</td>", $nfout/1000000);
 	if ($debug) {
-          echo "<TD ALIGN=\"right\">$insamples<TD ALIGN=\"right\">$outsamples<TD ALIGN=\"right\">$inignore<TD ALIGN=\"right\">$outignore";
+          echo "<td align=\"right\">$insamples</td><td align=\"right\">$outsamples</td><td align=\"right\">$inignore</td><td align=\"right\">$outignore</td>";
 	}
-	if ($yellow) echo "<TR BGCOLOR=\"#ffffcc\">\n";
-	else echo "<TR BGCOLOR=\"#94D6E7\">\n";
+        echo "</tr>\n";
+	if ($yellow) echo "<tr bgcolor=\"#ffffcc\">\n";
+	else echo "<tr bgcolor=\"#94D6E7\">\n";
       }
-      echo "</TABLE>\n";
+      echo "</table>\n";
     }
   } else {
-    echo "Customer Name: <INPUT TYPE=\"text\" NAME=\"customer\"><BR>\n";
-    echo "<P><TABLE>\n";
-    echo "<TD>From: \n";
-    echo "<TD><INPUT TYPE=TEXT NAME=\"smonth\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "Customer Name: <input type=\"text\" name=\"customer\" /><br />\n";
+    echo "<p><table>\n";
+    echo "<tr><td>From: </td>\n";
+    echo "<td><input type=\"text\" name=\"smonth\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("m"));
-    echo "\"> / \n";
-    echo "<INPUT TYPE=TEXT NAME=\"sday\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "\" /> / \n";
+    echo "<input type=\"text\" name=\"sday\" size=\"3\" maxlength=\"2\" value=\"";
     printf("%02d", (date("d") - 1));
-    echo "\"> / \n";
-    echo "<INPUT TYPE=TEXT NAME=\"syear\" SIZE=5 MAXLENGTH=4 VALUE=\"";
+    echo "\" /> / \n";
+    echo "<input type=\"text\" name=\"syear\" size=\"5\" maxlength=\"4\" value=\"";
     print (date("Y"));
-    echo "\">\n";
-    echo "<TD><INPUT TYPE=TEXT NAME=\"shour\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "\" /></td>\n";
+    echo "<td><input type=\"text\" name=\"shour\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("H"));
-    echo "\">:\n";
-    echo "<INPUT TYPE=TEXT NAME=\"smin\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "\" />:\n";
+    echo "<input type=\"text\" name=\"smin\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("i"));
-    echo "\">\n";
+    echo "\" /></td></tr>\n";
 
-    echo "<TR><TD>To: \n";
-    echo "<TD><INPUT TYPE=TEXT NAME=\"emonth\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "<tr><td>To: </td>\n";
+    echo "<td><input type=\"text\" name=\"emonth\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("m"));
-    echo "\"> / \n";
-    echo "<INPUT TYPE=TEXT NAME=\"eday\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "\" /> / \n";
+    echo "<input type=\"text\" name=\"eday\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("d"));
-    echo "\"> / \n";
-    echo "<INPUT TYPE=TEXT NAME=\"eyear\" SIZE=5 MAXLENGTH=4 VALUE=\"";
+    echo "\" /> / \n";
+    echo "<input type=\"text\" name=\"eyear\" size=\"5\" maxlength=\"4\" value=\"";
     print (date("Y"));
-    echo "\">\n";
-    echo "<TD><INPUT TYPE=TEXT NAME=\"ehour\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "\" /></td>\n";
+    echo "<td><input type=\"text\" name=\"ehour\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("H"));
-    echo "\">:\n";
-    echo "<INPUT TYPE=TEXT NAME=\"emin\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+    echo "\" />:\n";
+    echo "<input type=\"text\" name=\"emin\" size=\"3\" maxlength=\"2\" value=\"";
     print (date("i"));
-    echo "\">\n";
-    echo "<TR><TD>Debug: \n";
-    echo "<TD><INPUT TYPE=CHECKBOX NAME=\"debug\">\n";
-    echo "</TABLE>\n";
+    echo "\" /></td></tr>\n";
+    echo "<tr><td>Debug: </td>\n";
+    echo "<td><input type=\"checkbox\" name=\"debug\" /></td></tr>\n";
+    echo "</table>\n";
 
-    echo "<P><INPUT TYPE=\"SUBMIT\" VALUE=\"Ok\">";
+    echo "<p><input type=\"submit\" VALUE=\"Ok\" />";
   }
 
-  if ($dbc) mysql_close($dbc);
-  echo "</FORM>\n";
+  if ($dbc) mysqli_close($dbc);
+  echo "</form>\n";
 ?>
-<BR>
-<HR>
-<FONT FACE="Arial" SIZE="2">
+<br />
+<hr />
+<font face="Arial" size="2">
 <?php
- print "<A HREF=\"http://rtg.sourceforge.net\">RTG</A> Version $VERSION</FONT>";
+ print "<a href=\"http://rtg.sourceforge.net\">RTG</a> Version $VERSION</font>";
 ?>
-</BODY>
-</HTML>
+</body>
+</html>
