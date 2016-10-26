--- etc/95.php.orig	2003-09-24 20:40:57 UTC
+++ etc/95.php
@@ -4,10 +4,8 @@
   print "<HTML>\n<!-- RTG Version $VERSION -->\n<HEAD>\n";
 
   /* Connect to RTG MySQL Database */
-  $dbc=@mysql_connect ($host, $user, $pass) or
-  $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or 
+  $dbc=@mysqli_connect ($host, $user, $pass, $db) or
      die ("MySQL Connection Failed, Check Configuration.");
-  mysql_select_db($db,$dbc);
 
   if ($PHP_SELF == "") {
     $PHP_SELF = "95.php";
@@ -50,8 +48,8 @@ function int_stats($statement, $dbc) {
   $max = $avg = $nintyfifth = 0;
   $rate = array();
 
-  $selectResult=mysql_query($statement, $dbc);
-  while ($selectRow=mysql_fetch_object($selectResult)){
+  $selectResult=mysqli_query($dbc, $statement);
+  while ($selectRow=mysqli_fetch_object($selectResult)){
     $counter = $selectRow->counter;
     $sample_secs = $selectRow->unixtime;
     $total += $counter;
@@ -89,9 +87,8 @@ Report: 95th percentile<BR>
 <?php
   echo "<FORM ACTION=\"$PHP_SELF\" METHOD=\"GET\">\n";
   if (($bt || $smonth)) { 
-    $dbc=@mysql_connect ($host, $user, $pass) or
-    $dbc=@mysql_connect ("$host:/var/lib/mysql/mysql.sock", $user, $pass) or die ("MySQL Connection Failed, Check Configuration.");
-    mysql_select_db($db,$dbc);
+    $dbc=@mysqli_connect ($host, $user, $pass, $db) or
+      die ("MySQL Connection Failed, Check Configuration.");
     /* Format into GNU date syntax */
     if ($bt == "") {
       $bt = strtotime("$syear-$smonth-$sday $shour:$smin:00");
@@ -104,11 +101,11 @@ Report: 95th percentile<BR>
     $range="dtime>FROM_UNIXTIME($bt) AND dtime<=FROM_UNIXTIME($et)";
 
     $selectQuery="SELECT id, name, description, rid FROM interface WHERE description LIKE \"%$customer%\"";
-    $selectResult=mysql_query($selectQuery, $dbc);
-    if (mysql_num_rows($selectResult) <= 0) 
+    $selectResult=mysqli_query($dbc, $selectQuery);
+    if (mysqli_num_rows($selectResult) <= 0) 
       print "<BR>No Such Customer Found.<BR>\n";
     else {
-      while ($selectRow=mysql_fetch_object($selectResult)){
+      while ($selectRow=mysqli_fetch_object($selectResult)){
         $ids[$selectRow->id] = $selectRow->name; 
         $rids[$selectRow->id] = $selectRow->rid; 
 	$desc[$selectRow->id] = $selectRow->description;
@@ -127,8 +124,8 @@ Report: 95th percentile<BR>
       foreach($ids as $iid=>$name) {
 
         $selectQuery="SELECT name FROM router WHERE rid=$rids[$iid]";
-        $selectResult=mysql_query($selectQuery, $dbc);
-        $selectRow=mysql_fetch_object($selectResult);
+        $selectResult=mysqli_query($dbc, $selectQuery);
+        $selectRow=mysqli_fetch_object($selectResult);
 	$router = $selectRow->name;
 
         if ($yellow) $yellow = 0;
@@ -201,7 +198,7 @@ Report: 95th percentile<BR>
     echo "<P><INPUT TYPE=\"SUBMIT\" VALUE=\"Ok\">";
   }
 
-  if ($dbc) mysql_close($dbc);
+  if ($dbc) mysqli_close($dbc);
   echo "</FORM>\n";
 ?>
 <BR>
