--- etc/view.php.orig	2003-09-26 15:58:34 UTC
+++ etc/view.php
@@ -8,154 +8,163 @@
   header("Cache-Control: no-cache, must-revalidate");
   header("Pragma: no-cache");
 
-  print "<HTML>\n<!-- RTG Version $VERSION -->\n<HEAD>\n";
+  print "<html>\n<!-- RTG Version $VERSION -->\n<head>\n";
 
   /* Connect to RTG MySQL Database */
-  $dbc=@mysql_connect ($host, $user, $pass) or
-  $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or 
+  $dbc=@mysqli_connect ($host, $user, $pass, $db) or
      die ("MySQL Connection Failed, Check Configuration.");
-  mysql_select_db($db,$dbc);
 
   # Global variables off by default in newer versions of PHP
-  if (!$PHP_SELF) {
+  if (!isset($PHP_SELF) || ($PHP_SELF == "")) {
     $PHP_SELF = "view.php";
-    $rid = $_GET['rid'];
-    $iid = $_GET['iid'];
+    $rid = isset($_GET['rid'])?$_GET['rid']:"";
+    $iid = isset($_GET['iid'])?$_GET['iid']:"";
   }
 
   # Determine router, interface names as necessary
-  if ($rid && $iid) {
-    $selectQuery="SELECT a.name, a.description, a.speed, b.name AS router FROM interface a, router b WHERE a.rid=b.rid AND a.rid=$rid AND a.id=$iid";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $selectRow=mysql_fetch_object($selectResult);
-    $interfaces = mysql_num_rows($selectResult);
+  if (($rid != "") && ($iid != "")) {
+    $selectQuery="SELECT `a`.`name`, `a`.`description`, `a`.`speed`, `b`.`name` " .
+      "AS `router` FROM `interface` `a`, `router` `b` WHERE `a`.`rid`=`b`.`rid` " .
+      "AND `a`.`rid`=" . mysqli_real_escape_string($dbc, $rid) . " AND `a`.`id`=" .
+      mysqli_real_escape_string($dbc, $iid);
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
+  } else if (($rid != "")&& ($iid == "")) {
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
+  else if (($rid != "")&& ($iid == "")) echo "$router";
+  echo "</title>\n";
 
-  print "<meta HTTP-EQUIV=\"Refresh\" CONTENT=\"300\">\n";
-  print "<meta HTTP-EQUIV=\"Pragma\" CONTENT=\"no-cache\">\n";
-  print "<meta HTTP-EQUIV=\"Cache-Control\" CONTENT=\"no-cache\">\n";
-  print "<meta HTTP-EQUIV=\"Expires\" CONTENT=\"".gmdate('D, d M Y H:i:s \G\M\T', time() + 300)."\">\n";
-  print "<meta HTTP-EQUIV=\"Generator\" CONTENT=\"RTG $VERSION\">\n";
-  print "<meta HTTP-EQUIV=\"Date\" CONTENT=\"".gmdate('D, d M Y H:i:s \G\M\T', time())."\">\n";
-  print "<meta HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-1\">\n";
+  print "<meta http-equiv=\"Refresh\" content=\"300\" />\n";
+  print "<meta http-equiv=\"Pragma\" content=\"no-cache\" />\n";
+  print "<meta http-equiv=\"Cache-Control\" content=\"no-cache\" />\n";
+  print "<meta http-equiv=\"Expires\" content=\"".gmdate('D, d M Y H:i:s \G\M\T', time() + 300)."\" />\n";
+  print "<meta http-equiv=\"Generator\" content=\"RTG $VERSION\" />\n";
+  print "<meta http-equiv=\"Date\" content=\"".gmdate('D, d M Y H:i:s \G\M\T', time())."\" />\n";
+  print "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\" />\n";
 ?>
 
-</HEAD>
-<BODY BGCOLOR="ffffff">
-<A HREF="http://rtg.sourceforge.net" ALT="[RTG Home Page]">
-<IMG SRC="rtg.png" BORDER="0"></A><P><HR>
+</head>
+<body bgcolor="ffffff">
+<a href="http://rtg.sourceforge.net"<img src="rtg.png" border="0" alt="[RTG Home Page]" /></a><p><hr />
 
 <?php
- echo "<FORM ACTION=\"$PHP_SELF\" METHOD=\"GET\">\n";
+ echo "<form action=\"$PHP_SELF\" method=\"get\">\n";
 
  $et = time();
  
- if (!$rid) {
+ if ($rid == "") {
     print "Monitored Devices: <P>\n";
-    $selectQuery="SELECT rid, name FROM router";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    if (mysql_num_rows($selectResult) <= 0) 
-      print "<BR>No Routers Found.<BR>\n";
+    $selectQuery="SELECT `rid`, `name` FROM `router`";
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    if (mysqli_num_rows($selectResult) <= 0) 
+      print "<br />No Routers Found.<br />\n";
     else {
-      print "<UL>\n";
-      while ($selectRow=mysql_fetch_object($selectResult)){
-        print "<LI><A HREF=\"$PHP_SELF?rid=$selectRow->rid\">";
-        print "$selectRow->name</A><BR>\n";
+      print "<ul>\n";
+      while ($selectRow=mysqli_fetch_object($selectResult)){
+        print "<li><a href=\"$PHP_SELF?rid=$selectRow->rid\">";
+        print "$selectRow->name</a></li><br />\n";
       }
-      print "</UL>\n";
+      print "</ul>\n";
     }
  }
 
- if ($rid && $iid) {
+ if (($rid != "") && ($iid != "")) {
     if ($interfaces <= 0)
-      print "<BR>Interface $iid Not Found for Router $router (ID: $rid).<BR>\n";
+      print "<br />Interface $iid Not Found for Router $router (ID: $rid).<br />\n";
     else {
-      print "<TABLE>\n";
-      print "<TD>System:<TD>$router\n";
-      print "<TR><TD>Interface:<TD>$name\n";
-      print "<TR><TD>Description:<TD>$description\n";
-      print "<TR><TD>Speed:<TD>$speed Mbps\n";
-      print "<TR><TD>Page Generated:<TD>".gmdate('D, d M Y H:i:s \G\M\T', time())."\n";
-      print "</TABLE><HR>\n";
+      print "<table>\n";
+      print "<tr><td>System:</td><td>$router</td></tr>\n";
+      print "<tr><td>Interface:</td><td>$name</td></tr>\n";
+      print "<tr><td>Description:</td><td>$description</td></tr>\n";
+      print "<tr><td>Speed:</td><td>$speed Mbps</td></tr>\n";
+      print "<tr><td>Page Generated:</td><td>".gmdate('D, d M Y H:i:s \G\M\T', time())."</td></tr>\n";
+      print "</table><hr />\n";
 
       $bt = $et - (60*60*24);
-      print "<B>Day View:</B><BR>\n";
-      print "<IMG SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\">\n";
-      print "<BR><B>$router: $name ($description)</B>\n";
-      print "<BR><HR>\n";
+      print "<b>Day View:</b><br />\n";
+      print "<img src=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&amp;t2=ifOutOctets_".$rid."&amp;iid=$iid&amp;begin=$bt&amp;end=$et&amp;units=bits/s&amp;factor=8&amp;filled=yes";
+      print "&amp;title=" . urlencode("$router: $name ($description)") . "&amp;t1_name=" . urlencode("Input Octets") . "&amp;t2_name=" . urlencode("Output Octets") . "\" />\n";
+      print "<br /><b>$router: $name ($description)</b>\n";
+      print "<br /><hr />\n";
 
       $bt = $et - (60*60*24*7);
-      print "<B>Week View:</B><BR>\n";
-      print "<IMG SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\">\n";
-      print "<BR><B>$router: $name ($description)</B>\n";
-      print "<BR><HR>\n";
+      print "<b>Week View:</b><br />\n";
+      print "<img src=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&amp;t2=ifOutOctets_".$rid."&amp;iid=$iid&amp;begin=$bt&amp;end=$et&amp;units=bits/s&amp;factor=8&amp;filled=yes";
+      print "&amp;title=" . urlencode("$router: $name ($description)") . "&amp;t1_name=" . urlencode("Input Octets") . "&amp;t2_name=" . urlencode("Output Octets") . "\" />\n";
+      print "<br /><b>$router: $name ($description)</b>\n";
+      print "<br /><hr />\n";
 
       $bt = $et - (60*60*24*30);
-      print "<B>Month View:</B><BR>\n";
-      print "<IMG SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\">\n";
-      print "<BR><B>$router: $name ($description)</B>\n";
-      print "<BR><BR>\n";
+      print "<b>Month View:</b><br />\n";
+      print "<img src=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&amp;t2=ifOutOctets_".$rid."&amp;iid=$iid&amp;begin=$bt&amp;end=$et&amp;units=bits/s&amp;factor=8&amp;filled=yes";
+      print "&amp;title=" . urlencode("$router: $name ($description)") . "&amp;t1_name=" . urlencode("Input Octets") . "&amp;t2_name=" . urlencode("Output Octets") . "\" />\n";
+      print "<br /><b>$router: $name ($description)</b>\n";
+      print "<br /><br />\n";
     }
-    print "<INPUT TYPE=\"SUBMIT\" VALUE=\"Back to Main\">\n";
+    print "<input type=\"submit\" value=\"Back to Main\" />\n";
  }
 
- if ($rid && !$iid) {
-    $selectQuery="SELECT id, name, description FROM interface WHERE rid=$rid";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    $interfaces = mysql_num_rows($selectResult);
+ if (($rid != "") && ($iid == "")) {
+    $selectQuery="SELECT `id`, `name`, `description` FROM `interface` WHERE " .
+      "`rid`=" . mysqli_real_escape_string($dbc, $rid);
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    $interfaces = mysqli_num_rows($selectResult);
     if ($interfaces <= 0) 
-      print "<BR>No Interfaces Found for Router $router (ID: $rid).<BR>\n";
+      print "<br />No Interfaces Found for Router $router (ID: $rid).<br />\n";
     else {
       $bt = $et - (60*60*12);
-      print "<TABLE>\n";
-      print "<TD>System:<TD>$router\n";
-      print "<TR><TD>Interfaces:<TD>$interfaces\n";
-      print "<TR><TD>Page Generated:<TD>";
-      print gmdate('D, d M Y H:i:s \G\M\T', time())."\n";
-      print "</TABLE><HR>\n";
-      print "<TABLE BORDER=\"0\" CELLPADDING=\"0\" CELLSPACING=\"10\">\n";
-      while ($selectRow=mysql_fetch_object($selectResult)){
+      print "<table>\n";
+      print "<tr><td>System:</td><td>$router</td></tr>\n";
+      print "<tr><td>Interfaces:</td><td>$interfaces</td></tr>\n";
+      print "<tr><td>Page Generated:</td><td>";
+      print gmdate('D, d M Y H:i:s \G\M\T', time())."</td></tr>\n";
+      print "</table><hr />\n";
+      print "<table border=\"0\" cellpadding=\"0\" cellspacing=\"10\">\n";
+      print "<tr>\n";
+      while ($selectRow=mysqli_fetch_object($selectResult)){
         $ids[$selectRow->id] = $selectRow->name; 
 	$desc[$selectRow->id] = $selectRow->description;
 	$iid = $selectRow->id;
-	print "<TD><A HREF=\"$PHP_SELF?rid=$rid&iid=$iid\">\n";
-	print "<IMG HEIGHT=\"135\" WIDTH=\"500\" SRC=\"rtgplot.cgi?t1=ifInOctets_".$rid."&t2=ifOutOctets_".$rid."&iid=$iid&begin=$bt&end=$et&units=bits/s&factor=8&filled=yes\" BORDER=\"0\">\n";
-	print "</A><BR>\n";
-        print "<B>$selectRow->name ($selectRow->description)</B>\n";
-        if ($even) {
+	print "<td><a href=\"$PHP_SELF?rid=$rid&amp;iid=$iid\">\n";
+	print "<img height=\"135\" width=\"500\" src=\"/cgi-bin/rtgplot.cgi?t1=ifInOctets_".$rid."&amp;t2=ifOutOctets_".$rid;
+	print "&amp;title=" . urlencode("$router: " . $selectRow->name . " (" . $selectRow->description . ")");
+	print "&amp;t1_name=" . urlencode("Input Octets") . "&t2_name=" . urlencode("Output Octets");
+	print "&amp;iid=$iid&amp;begin=$bt&amp;end=$et&amp;units=bits/s&amp;factor=8&amp;filled=yes\" border=\"0\" />\n";
+	print "</a><br />\n";
+        print "<b>$selectRow->name ($selectRow->description)</b>\n";
+        if ($even == 1) {
 	  $even = 0;
-	  print "<TR>\n";
+	  print "</tr><tr>\n";
 	}
 	else $even = 1;
       }
-      print "</TABLE>\n";
+      print "</tr></table>\n";
     }
-    print "<INPUT TYPE=\"SUBMIT\" VALUE=\"Back to Main\">\n";
+    print "<input type=\"submit\" value=\"Back to Main\" />\n";
   }
 
-  if ($dbc) mysql_close($dbc);
-  echo "</FORM>\n";
+  if ($dbc) mysqli_close($dbc);
+  echo "</form>\n";
 ?>
 
-<HR>
-<FONT FACE="Arial" SIZE="2">
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
