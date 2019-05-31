--- etc/rtg.php.orig	2003-09-24 20:42:03 UTC
+++ etc/rtg.php
@@ -1,146 +1,152 @@
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
 
- if ($PHP_SELF == "") {
+ if (!isset($PHP_SELF) || $PHP_SELF == "") {
    $PHP_SELF = "rtg.php";
-   $errors = $_GET['errors'];
-   $scalex = $_GET['scalex'];
-   $scaley = $_GET['scaley'];
-   $aggr = $_GET['aggr'];
-   $percentile = $_GET['percentile'];
-   $nth = $_GET['nth'];
-   $xplot = $_GET['xplot'];
-   $yplot = $_GET['yplot'];
-   $borderb = $_GET['borderb'];
-   $iid = $_GET['iid'];
-   $rid = $_GET['rid'];
-   $syear = $_GET['syear'];
-   $eyear = $_GET['eyear'];
-   $smonth = $_GET['smonth'];
-   $emonth = $_GET['emonth'];
-   $sday = $_GET['sday'];
-   $eday = $_GET['eday'];
-   $shour = $_GET['shour'];
-   $ehour = $_GET['ehour'];
-   $smin = $_GET['smin'];
-   $emin = $_GET['emin'];
+   $errors = isset($_GET['errors'])?$_GET['errors']:"";
+   $scalex = isset($_GET['scalex'])?$_GET['scalex']:"";
+   $scaley = isset($_GET['scaley'])?$_GET['scaley']:"";
+   $aggr = isset($_GET['aggr'])?$_GET['aggr']:"";
+   $percentile = isset($_GET['percentile'])?$_GET['percentile']:"";
+   $nth = isset($_GET['nth'])?$_GET['nth']:"";
+   $xplot = isset($_GET['xplot'])?$_GET['xplot']:"";
+   $yplot = isset($_GET['yplot'])?$_GET['yplot']:"";
+   $borderb = isset($_GET['borderb'])?$_GET['borderb']:"";
+   $iid = isset($_GET['iid'])?$_GET['iid']:"";
+   $rid = isset($_GET['rid'])?$_GET['rid']:"";
+   $syear = isset($_GET['syear'])?$_GET['syear']:"";
+   $eyear = isset($_GET['eyear'])?$_GET['eyear']:"";
+   $smonth = isset($_GET['smonth'])?$_GET['smonth']:"";
+   $emonth = isset($_GET['emonth'])?$_GET['emonth']:"";
+   $sday = isset($_GET['sday'])?$_GET['sday']:"";
+   $eday = isset($_GET['eday'])?$_GET['eday']:"";
+   $shour = isset($_GET['shour'])?$_GET['shour']:"";
+   $ehour = isset($_GET['ehour'])?$_GET['ehour']:"";
+   $smin = isset($_GET['smin'])?$_GET['smin']:"";
+   $emin = isset($_GET['emin'])?$_GET['emin']:"";
  }
 
   # Determine router, interface names as necessary
-  if ($rid && $iid) {
-    $selectQuery="SELECT a.name, a.description, a.speed, b.name AS router FROM interface a, router b WHERE a.rid=b.rid AND a.rid=$rid AND a.id=$iid[0]";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $selectRow=mysql_fetch_object($selectResult);
-    $interfaces = mysql_num_rows($selectResult);
+  if (($rid != "") && ($iid != "")) {
+    $selectQuery="SELECT `a`.`name`, `a`.`description`, `a`.`speed`, `b`.`name` " .
+      "AS `router` FROM `interface` `a`, `router` `b` WHERE `a`.`rid`=`b`.`rid` " .
+      "AND `a`.`rid`=" . mysqli_real_escape_string($dbc, $rid) . " AND `a`.`id`=" .
+      mysqli_real_escape_string($dbc, $iid[0]);
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    $selectRow=mysqli_fetch_object($selectResult);
+    $interfaces = mysqli_num_rows($selectResult);
     $name = $selectRow->name;
     $description = $selectRow->description;
     $speed = ($selectRow->speed)/1000000;
     $router = $selectRow->router;
-  } else if ($rid && !$iid) {
-    $selectQuery="SELECT name AS router from router where rid=$rid";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $selectRow=mysql_fetch_object($selectResult);
+  } else if (($rid != "") && ($iid == "")) {
+    $selectQuery="SELECT `name` AS `router` FROM `router` WHERE `rid`=" .
+      mysqli_real_escape_string($dbc, $rid);
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    $selectRow=mysqli_fetch_object($selectResult);
     $router = $selectRow->router;
   }
 
   # Generate Title 
-  echo "<TITLE>RTG: ";
-  if ($rid && $iid) echo "$router: $name";
-  else if ($rid && !$iid) echo "$router";
-  echo "</TITLE>\n";
+  echo "<title>RTG: ";
+  if (($rid != "") && ($iid != "")) echo "$router: $name";
+  else if (($rid != "") && ($iid == "")) echo "$router";
+  echo "</title>\n";
 ?>
 
-</HEAD>
-<BODY BACKGROUND="rtgback.png" BGCOLOR="ffffff">
-<A HREF="http://rtg.sourceforge.net" ALT="[RTG Home Page]">
-<IMG SRC="rtg.png" BORDER="0">
-</A>
-<P>
+</head>
+<body background="rtgback.png" bgcolor="ffffff">
+<a href="http://rtg.sourceforge.net" alt="[RTG Home Page]"><img src="rtg.png" border="0" /></a>
+<p>
 
 <?php
-echo "<FORM ACTION=\"$PHP_SELF\" METHOD=\"get\">\n";
+echo "<form action=\"$PHP_SELF\" method=\"get\">\n";
 
-if (!$rid && !$iid) {
- echo "<SELECT NAME=\"rid\" SIZE=10>\n";
- $selectQuery="SELECT DISTINCT name, rid FROM router ORDER BY name";
- $selectResult=mysql_query($selectQuery, $dbc);
- while ($selectRow=mysql_fetch_object($selectResult)){
-    echo "<OPTION VALUE=\"$selectRow->rid\">$selectRow->name\n";
+if (($rid == "") && ($iid == "")) {
+ echo "<select name=\"rid\" size=\"10\">\n";
+ $selectQuery="SELECT DISTINCT `name`, `rid` FROM `router` ORDER BY `name`";
+ $selectResult=mysqli_query($dbc, $selectQuery);
+ while ($selectRow=mysqli_fetch_object($selectResult)){
+    echo "<option value=\"$selectRow->rid\">$selectRow->name</option>\n";
  }
- echo "</SELECT>\n";
+ echo "</select>\n";
 }
 
-if ($smonth != "" && $iid == "") {
- echo "<BLOCKQUOTE><FONT SIZE=+1><STRONG>\n";
+if (($smonth != "") && ($iid == "")) {
+ echo "<blockquote><font size=\"+1\"><b>\n";
  echo "Please select an interface!\n";
- echo "</FONT></STRONG></BLOCKQUOTE>\n";
+ echo "</b></font></blockquote>\n";
 }
 
-if ($rid && !$iid) {
-  echo "<SELECT NAME=\"rid\" SIZE=10>\n"; 
-  echo "<OPTION SELECTED VALUE=\"$rid\">$router\n";
-  echo "</SELECT>\n";
+if (($rid != "") && ($iid == "")) {
+  echo "<select name=\"rid\" size=\"10\">\n"; 
+  echo "<option selected value=\"$rid\">$router</option>\n";
+  echo "</select>\n";
 
-  echo "<SELECT MULTIPLE NAME=\"iid[]\" SIZE=10>\n"; 
-  $selectQuery="SELECT id, name, description FROM interface WHERE rid=$rid ORDER BY name";
-  $selectResult=mysql_query($selectQuery, $dbc);
-  while ($selectRow=mysql_fetch_object($selectResult)){
-     echo "<OPTION VALUE=\"$selectRow->id\">$selectRow->name ($selectRow->description)\n";
+  echo "<select multiple name=\"iid[]\" size=\"10\">\n";
+  $selectQuery="SELECT `id`, `name`, `description` FROM `interface` WHERE " .
+    "`rid`=" . mysqli_real_escape_string($dbc, $rid) . " ORDER BY `name`";
+  $selectResult=mysqli_query($dbc, $selectQuery);
+  while ($selectRow=mysqli_fetch_object($selectResult)){
+     echo "<option value=\"$selectRow->id\">$selectRow->name ($selectRow->description)</option>\n";
   }
-  echo "</SELECT>\n";
+  echo "</select>\n";
 
-  echo "<P><TABLE>\n";
-  echo "<TD>From: \n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"smonth\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+  echo "<p><table>\n";
+  echo "<tr><td>From: </td>\n";
+  echo "<td><input type=\"text\" name=\"smonth\" size=\"3\" maxlength=\"2\" value=\"";
   print (date("m"));
-  echo "\"> / \n";
-  echo "<INPUT TYPE=TEXT NAME=\"sday\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+  echo "\" /> / \n";
+  echo "<input type=\"text\" name=\"sday\" size=\"3\" maxlength=\"2\" value=\"";
   print (date("d"));
-  echo "\"> / \n";
-  echo "<INPUT TYPE=TEXT NAME=\"syear\" SIZE=5 MAXLENGTH=4 VALUE=\"";
+  echo "\" /> / \n";
+  echo "<input type=\"text\" name=\"syear\" size=\"5\" maxlength=\"4\" value=\"";
   print (date("Y"));
-  echo "\">\n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"shour\" SIZE=3 MAXLENGTH=2 VALUE=\"00\">:\n";
-  echo "<INPUT TYPE=TEXT NAME=\"smin\" SIZE=3 MAXLENGTH=2 VALUE=\"00\">\n";
+  echo "\" />\n";
+  echo "</td>";
+  echo "<td><input type=\"text\" name=\"shour\" size=\"3\" maxlength=\"2\" value=\"00\" />:\n";
+  echo "<input type=\"text\" name=\"smin\" size=\"3\" maxlength=\"2\" value=\"00\" />\n";
+  echo "</td></tr>\n";
 
-  echo "<TR><TD>To: \n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"emonth\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+  echo "<tr><td>To: </td>\n";
+  echo "<td><input type=\"text\" name=\"emonth\" size=\"3\" maxlength=\"2\" value=\"";
   print (date("m"));
-  echo "\"> / \n";
-  echo "<INPUT TYPE=TEXT NAME=\"eday\" SIZE=3 MAXLENGTH=2 VALUE=\"";
+  echo "\" /> / \n";
+  echo "<input type=\"text\" name=\"eday\" size=\"3\" maxlength=\"2\" value=\"";
   print (date("d"));
-  echo "\"> / \n";
-  echo "<INPUT TYPE=TEXT NAME=\"eyear\" SIZE=5 MAXLENGTH=4 VALUE=\"";
+  echo "\" /> / \n";
+  echo "<input type=\"text\" name=\"eyear\" size=\"5\" maxlength=\"4\" value=\"";
   print (date("Y"));
-  echo "\">\n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"ehour\" SIZE=3 MAXLENGTH=2 VALUE=\"23\">:\n";
-  echo "<INPUT TYPE=TEXT NAME=\"emin\" SIZE=3 MAXLENGTH=2 VALUE=\"59\">\n";
-  echo "<TR><TD>Aggregate Interfaces: \n";
-  echo "<TD><INPUT TYPE=CHECKBOX NAME=\"aggr\">\n";
-  echo "<TR><TD><INPUT TYPE=TEXT NAME=\"nth\" SIZE=2 MAXLENGTH=2 VALUE=\"95\">th Percentile: \n";
-  echo "<TD><INPUT TYPE=CHECKBOX NAME=\"percentile\">\n";
-  echo "<TR><TD>Fit to Data: \n";
-  echo "<TD><INPUT TYPE=CHECKBOX NAME=\"scalex\">\n";
-  echo "<TR><TD>Fit to Speed: \n";
-  echo "<TD><INPUT TYPE=CHECKBOX NAME=\"scaley\">\n";
-  echo "<TR><TD>X Size: \n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"xplot\" SIZE=3 VALUE=\"500\">\n";
-  echo "<TR><TD>Y Size: \n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"yplot\" SIZE=3 VALUE=\"150\">\n";
-  echo "<TR><TD>BorderB: \n";
-  echo "<TD><INPUT TYPE=TEXT NAME=\"borderb\" SIZE=3 VALUE=\"70\">\n";
-  echo "</TABLE>\n";
+  echo "\" />\n";
+  echo "</td>";
+  echo "<td><input type=\"text\" name=\"ehour\" size=\"3\" maxlength=\"2\" value=\"23\" />:\n";
+  echo "<input type=\"text\" name=\"emin\" size=\"3\" maxlength=\"2\" value=\"59\" />\n";
+  echo "</td></tr>\n";
+
+  echo "<tr><td>Aggregate Interfaces: </td>\n";
+  echo "<td><input type=\"checkbox\" name=\"aggr\" /></td></tr>\n";
+  echo "<tr><td><input type=\"text\" name=\"nth\" size=\"2\" maxlength=\"2\" value=\"95\" />th Percentile: </td>\n";
+  echo "<td><input type=\"checkbox\" name=\"percentile\" /></td></tr>\n";
+  echo "<tr><td>Fit to Data: </td>\n";
+  echo "<td><input type=\"checkbox\" name=\"scalex\" /></td></tr>\n";
+  echo "<tr><td>Fit to Speed: </td>\n";
+  echo "<td><input type=\"checkbox\" name=\"scaley\" /></td></tr>\n";
+  echo "<tr><td>X Size: </td>\n";
+  echo "<td><input type=\"text\" name=\"xplot\" size=\"3\" value=\"500\" /></td></tr>\n";
+  echo "<tr><td>Y Size: </td>\n";
+  echo "<td><input type=\"text\" name=\"yplot\" size=\"3\" value=\"150\" /></td></tr>\n";
+  echo "<tr><td>BorderB: </td>\n";
+  echo "<td><input type=\"text\" name=\"borderb\" size=\"3\" value=\"70\" /></td></tr>\n";
+  echo "</table>\n";
 }
 
-if (($bt || $smonth) && $iid) { 
+if (($bt != "" || $smonth != "") && ($iid != "")) { 
 
   /* Format into GNU date syntax */
   if ($bt == "") {
@@ -148,67 +154,84 @@ if (($bt || $smonth) && $iid) { 
     $et = strtotime("$eyear-$emonth-$eday $ehour:$emin:59");
   }
 
-  $range="dtime>FROM_UNIXTIME($bt) AND dtime<=FROM_UNIXTIME($et)";
-  $range="$range AND id=$iid[0]";
+  $range="`dtime`>FROM_UNIXTIME(" . mysqli_real_escape_string($dbc, $bt) . ") AND " .
+    "`dtime`<=FROM_UNIXTIME(" . mysqli_real_escape_string($dbc, $et) . ") " .
+    "AND `id`=" . mysqli_real_escape_string($dbc, $iid[0]);
 
-  $selectQuery="SELECT description, name, speed FROM interface WHERE rid=$rid AND id=$iid[0]";
-  $selectResult=mysql_query($selectQuery, $dbc);
-  $selectRow=mysql_fetch_object($selectResult);
-  echo "<TABLE BORDER=0>\n";
-  echo "<TD><I>Device</I>:</TD><TD>$router ($rid)</TD><TR>\n";
-  echo "<TD><I>Interface</I>:</TD><TD>$selectRow->name ($iid[0])</TD><TR>\n";
-  printf ("<TD><I>Speed</I>:</TD><TD>%2.3f Mbps</TD><TR>\n", $selectRow->speed / 1000000);
-  echo "<TD><I>Description</I>:</TD><TD>$selectRow->description</TD><TR>\n";
-  print strftime("<TD><I>Period</I>:</TD><TD>%m/%d/%Y %H:%M - ", $bt);
-  print strftime("%m/%d/%Y %H:%M</TD>\n", $et);
-  echo "</TABLE>\n";
-  echo "<P>\n";
+  $selectQuery="SELECT `description`, `name`, `speed` FROM `interface` WHERE " .
+    "`rid`=" . mysqli_real_escape_string($dbc, $rid) . " AND `id`=" .
+    mysqli_real_escape_string($dbc, $iid[0]);
+  $selectResult=mysqli_query($dbc, $selectQuery);
+  $selectRow=mysqli_fetch_object($selectResult);
+  echo "<table border=\"0\">\n";
+  echo "<tr><td><i>Device</i>:</td><td>$router ($rid)</td></tr>\n";
+  echo "<tr><td><i>Interface</i>:</td><td>$selectRow->name ($iid[0])</td></tr>\n";
+  printf ("<tr><td><i>Speed</i>:</td><td>%2.3f Mbps</td></tr>\n", $selectRow->speed / 1000000);
+  echo "<tr><td><i>Description</i>:</td><td>$selectRow->description</td></tr>\n";
+  print strftime("<tr><td><i>Period</i>:</td><td>%m/%d/%Y %H:%M - ", $bt);
+  print strftime("%m/%d/%Y %H:%M</td>\n", $et);
+  echo "</tr>\n";
+  echo "</table>\n";
+  echo "<p>\n";
  
   #$selectQuery="SELECT DISTINCT id FROM ifInOctets_$rid WHERE $range";
-  #$selectResult=mysql_query($selectQuery, $dbc);
-  #if (mysql_num_rows($selectResult) <= 0) {
+  #$selectResult=mysqli_query($dbc, $selectQuery);
+  #if (mysqli_num_rows($selectResult) <= 0) {
   #   print "<BR>No Data Found on Interface for Given Range.<BR>\n";
   #}
   #else {
-    $args = "t1=ifInOctets_$rid&t2=ifOutOctets_$rid&begin=$bt&end=$et&units=bits/s&factor=8";
+    $args = "t1=ifInOctets_$rid&amp;t2=ifOutOctets_$rid&amp;begin=$bt&amp;";
+    $args .= "end=$et&amp;units=bits/s&amp;factor=8";
+    $args .= "&amp;title=" . urlencode($selectRow->description);
+    $args .= "&amp;t1_name=" . urlencode("Input Octets");
+    $args .= "&amp;t2_name=" . urlencode("Output Octets");
     foreach ($iid as $value) {
-      $args="$args&iid=$value";
+      $args="$args&amp;iid=" . urlencode($value);
     }
-    if ($scalex) $args = "$args&scalex=yes";
-    if ($scaley) $args = "$args&scaley=yes";
-    if ($xplot) $args = "$args&xplot=$xplot";
-    if ($yplot) $args = "$args&yplot=$yplot";
-    if ($borderb) $args = "$args&borderb=$borderb";
-    if ($aggr) $args = "$args&aggr=yes";
-    if ($percentile) $args = "$args&percentile=$nth";
-    print "<IMG SRC=rtgplot.cgi?$args><BR>\n";
-    $args = "t1=ifInUcastPkts_$rid&t2=ifOutUcastPkts_$rid&begin=$bt&end=$et&units=pkts/s";
+    if ($scalex != "") $args = "$args&amp;scalex=yes";
+    if ($scaley != "") $args = "$args&amp;scaley=yes";
+    if ($xplot != "") $args = "$args&amp;xplot=$xplot";
+    if ($yplot != "") $args = "$args&amp;yplot=$yplot";
+    if ($borderb != "") $args = "$args&amp;borderb=$borderb";
+    if ($aggr != "") $args = "$args&amp;aggr=yes";
+    if ($percentile != "") $args = "$args&amp;percentile=$nth";
+    print "<img src=\"/cgi-bin/rtgplot.cgi?$args\" alt=\"graph\" /><br />\n";
+    $args = "t1=ifInUcastPkts_$rid&amp;t2=ifOutUcastPkts_$rid&amp;begin=$bt&amp;";
+    $args .= "end=$et&amp;units=pkts/s";
+    $args .= "&amp;title=" . urlencode($selectRow->description);
+    $args .= "&amp;t1_name=" . urlencode("Input Packets");
+    $args .= "&amp;t2_name=" . urlencode("Output Packets");
     foreach ($iid as $value) {
-      $args="$args&iid=$value";
+      $args="$args&amp;iid=" . urlencode($value);
+    }
+    if ($scalex != "") $args = "$args&amp;scalex=yes";
+    if ($xplot != "") $args = "$args&amp;xplot=$xplot";
+    if ($yplot != "") $args = "$args&amp;yplot=$yplot";
+    if ($borderb != "") $args = "$args&amp;borderb=$borderb";
+    if ($aggr != "") $args = "$args&amp;aggr=yes";
+    if ($percentile != "") $args = "$args&amp;percentile=$nth";
+    print "<img src=\"/cgi-bin/rtgplot.cgi?$args\" alt=\"graph\" /><br />\n";
+    if ($errors != "")
+    {
+       print "<img src=\"/cgi-bin/rtgplot.cgi?t1=ifInErrors_$rid&amp;begin=$bt";
+       print "&amp;end=$et&amp;units=errors&amp;impulses=yes";
+       print "&amp;title=" . urlencode($selectRow->description);
+       print "&amp;t1_name=" . urlencode("Errors") . "\" alt=\"graph\" />\n";
     }
-    if ($scalex) $args = "$args&scalex=yes";
-    if ($xplot) $args = "$args&xplot=$xplot";
-    if ($yplot) $args = "$args&yplot=$yplot";
-    if ($borderb) $args = "$args&borderb=$borderb";
-    if ($aggr) $args = "$args&aggr=yes";
-    if ($percentile) $args = "$args&percentile=$nth";
-    print "<IMG SRC=rtgplot.cgi?$args><BR>\n";
-    if ($errors) 
-       print "<IMG SRC=rtgplot.cgi?t1=ifInErrors_$rid&begin=$bt&end=$et&units=errors&impulses=yes>\n";
 #  }
 } 
 
-mysql_close($dbc);
+mysqli_close($dbc);
 ?>
 
-<P>
-<INPUT TYPE="SUBMIT" VALUE="Ok">
-</FORM>
-<BR>
-<HR>
-<FONT FACE="Arial" SIZE="2">
+<p>
+<input type="submit" value="Ok" />
+</form>
+<br />
+<hr />
+<font face="Arial" size="2">
 <?php
- print "<A HREF=\"http://rtg.sourceforge.net\">RTG</A> Version $VERSION</FONT>";
-?>
-</BODY>
-</HTML>
+ print "<a href=\"http://rtg.sourceforge.net\">RTG</a> Version $VERSION</font>";
+?></p>
+</body>
+</html>
