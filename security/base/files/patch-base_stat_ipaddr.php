--- ./base_stat_ipaddr.php.orig	2010-03-05 16:06:17.000000000 +0100
+++ ./base_stat_ipaddr.php	2010-04-11 23:52:13.000000000 +0200
@@ -135,7 +135,7 @@
    print "</PRE><BR>\n";
    */
 
-   if(ereg($ip, $contents)) {
+   if(preg_match("/$ip/", $contents)) {
      $total++;
      if( $total % 2 == 0 ) {
         $color="DDDDDD";
@@ -143,7 +143,7 @@
         $color="FFFFFF";
      }
 
-     $contents = ereg_replace("  ", " ", $contents);
+     $contents = preg_replace("/  /", " ", $contents);
      $elements = explode(" ", $contents);
 
      echo '<tr bgcolor="'.$color.'"><td align="center">'.
@@ -183,7 +183,7 @@
      print "</PRE></TD>";
 
      /*
-     ereg("([0-9]*\.[0-9]*\.[0-9]*\.[0-9]*):([0-9]*)",$elements[3],$store);
+     preg_match("/([0-9]*\.[0-9]*\.[0-9]*\.[0-9]*):([0-9]*)/",$elements[3],$store);
      $source_ip = $store[1];
      $source_port = $store[2];
      if (empty($source_ip))
@@ -197,7 +197,7 @@
      echo '<td align="center">' . $source_ip  . '</td>';
      echo '<td align="center">' . $source_port . '</td>';
 
-     ereg("([0-9]*\.[0-9]*\.[0-9]*\.[0-9]*):([0-9]*)",$elements[5],$store);
+     preg_match("/([0-9]*\.[0-9]*\.[0-9]*\.[0-9]*):([0-9]*)/",$elements[5],$store);
      $destination_ip = $store[1];
      $destination_port = $store[2];
      if (empty($destination_ip))
