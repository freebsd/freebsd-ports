--- php/hawk.php.orig	2001-11-08 21:58:52.000000000 +0000
+++ php/hawk.php	2012-02-05 12:09:21.000000000 +0000
@@ -10,6 +10,7 @@
    # map these variables
    $sortby=$HTTP_POST_VARS["sortby"];
    $network=$HTTP_POST_VARS["network"];
+   $for_rev_check=$HTTP_POST_VARS["for_rev_check"];
    $showeverydamnthing=$HTTP_POST_VARS["showeverydamnthing"];
 
    $sortoptions = array (
@@ -38,6 +39,18 @@
 
    print "</table>\n";
 
+   print "<br>";
+
+   if ($for_rev_check || ($for_rev_check_default && !$network)) {
+      $checked = "checked";
+   }
+   else {
+      $checked = "";
+   }
+   checkbox("for_rev_check", $checked);
+   print "&nbsp;&nbsp;<font size=-1>Indicate if the forward and reverse hostnames match.</font>";
+   print "<br>";
+
    if ($showeverydamnthing) {
       $checked = "checked";
    }
@@ -51,7 +64,6 @@
    print "</form>";
 
 #   href("#key", "Key");
-   print "<br>";
 
    # show everything until network selection is implemented
    if ($network) {
@@ -70,7 +82,7 @@
    #####################################################
    function shownet ($network) {
 
-      global $dbuser, $dbpass, $dbhost, $dbname, $redzone, $yellowzone, $sortby, $showeverydamnthing;
+      global $dbuser, $dbpass, $dbhost, $dbname, $redzone, $yellowzone, $sortby, $for_rev_check, $showeverydamnthing, $purple_string;
       if (!$link=@mysql_connect($dbhost, $dbuser, $dbpass)) {
          $errormsg = mysql_error();
          print urlencode($errormsg);
@@ -87,10 +99,10 @@
 
 # select them all for now
       if ($sortby == ip) {
-         $query = "select ip, hostname, lastping from hawk.ip order by inet_aton(ip)";
+         $query = "select ip, hostname, lastping, for_rev_match from hawk.ip order by inet_aton(ip)";
       }
       else {
-         $query = "select ip, hostname, lastping from hawk.ip order by '$sortby'";
+         $query = "select ip, hostname, lastping, for_rev_match from hawk.ip order by '$sortby'";
       }
          
       if (!$result = @mysql_query($query)) {
@@ -110,7 +122,7 @@
          extract ($record);
 
          # only show blank ping/hostname records if $showeverydamnthing is set
-         if ($hostname == "" && $lastping == 0 && !$showeverydamnthing) continue 1;
+         if ((!$hostname || strstr($hostname, $purple_string)) && !$lastping && !$showeverydamnthing) continue 1;
 
 if (!testip($network, $ip)) continue 1;
 
@@ -126,24 +138,28 @@
          print "<tr>";
 
          # no hostname, no ping response
-         if (!$hostname && !$lastping) {
-            print "<td>";img("images/purplesphere.png");print "</td>";
+         if ((!$hostname || strstr($hostname, $purple_string)) && !$lastping) {
+            print "<td>";img("images/purplesphere.png", 20, 20, "purple");print "</td>";
          }
          # ping response, but no hostname
          elseif ($lastping > (time() - $redzone) && !$hostname) {
-            print "<td>";img("images/bluesphere.png");print "</td>";
+            print "<td>";img("images/bluesphere.png", 20, 20, "blue");print "</td>";
+         }
+         # forward and reverse hostnames do not match
+         elseif ($for_rev_check && !$for_rev_match) {
+            print "<td>";img("images/questionsphere.png", 20, 20, "question");print "</td>";
          }
          # ping response in "red zone"
          elseif ((time() - $redzone) > $lastping) {
-            print "<td>";img("images/redsphere.png");print "</td>";
+            print "<td>";img("images/redsphere.png", 20, 20, "red");print "</td>";
          }
          # ping response in "yellow zone"
          elseif ((time() - $yellowzone) > $lastping) {
-            print "<td>";img("images/yellowsphere.png");print "</td>";
+            print "<td>";img("images/yellowsphere.png", 20, 20, "yellow");print "</td>";
          }
          # recent ping response, hostname ok
          else {
-            print "<td>";img("images/greensphere.png");print "</td>";
+            print "<td>";img("images/greensphere.png", 20, 20, "green");print "</td>";
          }
          print "<td>$ip</td>";
          print "<td>$hostname&nbsp;</td>";
@@ -160,28 +176,34 @@
    #####################################################
    function showkey () {
 
-      global $yellowzone, $redzone;
+      global $for_rev_check, $yellowzone, $redzone;
 
       print "<table>\n";
 
       print "<tr><td>Key:&nbsp;&nbsp;</td><td>";
-      img("images/greensphere.png", 10, 10);
+      img("images/greensphere.png", 10, 10, "green");
       print " Host in DNS.  Recent ping response.<td></tr>";
 
+      if ($for_rev_check) {
+         print "<tr><td></td><td>";
+         img("images/questionsphere.png", 10, 10, "question");
+         print " Host in DNS.  Forward and reverse hostnames do not match.</td></tr>\n";
+      }
+
       print "<tr><td></td><td>";
-      img("images/yellowsphere.png", 10, 10);
+      img("images/yellowsphere.png", 10, 10, "yellow");
       print " Host in DNS.  No ping response for over $yellowzone seconds.</td></tr>\n";
 
       print "<tr><td></td><td>";
-      img("images/redsphere.png", 10, 10);
+      img("images/redsphere.png", 10, 10, "red");
       print " Host in DNS.  No ping response for over $redzone seconds.</td></tr>\n";
 
       print "<tr><td></td><td>";
-      img("images/purplesphere.png", 10, 10);
+      img("images/purplesphere.png", 10, 10, "purple");
       print " Host not in DNS.  No ping response.</td></tr>\n";
 
       print "<tr><td></td><td>";
-      img("images/bluesphere.png", 10, 10);
+      img("images/bluesphere.png", 10, 10, "blue");
       print " Host not in DNS.  Recent ping response.</td></tr>\n";
 
       print "</table>";
@@ -196,6 +218,8 @@
          <html>
          <head>
          <link rel="stylesheet" type="text/css" href="hawk.css" title="Hawk Style Sheet">
+         <link rel="icon" type="image/vnd.microsoft.icon" href="images/favicon.ico">
+         <link rel="shortcut icon" href="images/favicon.ico" />
          <title></title>
          </head>
          <body>
@@ -244,9 +268,9 @@
 
    }
 
-   function img ($image, $height="", $width="") {
+   function img ($image, $height="", $width="", $text="") {
 
-      print "<img src=$image height=$height width=$width>";
+      print "<img src=$image height=$height width=$width title=$text alt=$text>";
 
    }
 
