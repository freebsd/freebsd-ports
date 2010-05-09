--- ./base_graph_display.php.orig	2010-03-05 16:06:17.000000000 +0100
+++ ./base_graph_display.php	2010-04-11 23:52:13.000000000 +0200
@@ -320,27 +320,27 @@
 
       // special case '"I0" => "private network (rfc 1918)"' and
       // '"** (private network) " => "private network (rfc 1918)"'
-      if (ereg("rfc 1918", $tmp, $substring) || (ereg("[*][*] \(private network\) ", $tmp_lower, $substring)))
+      if (preg_match("/rfc 1918/", $tmp, $substring) || (preg_match("/[*][*] \(private network\) /", $tmp_lower, $substring)))
       {
         $Dataset->addPoint("private network (rfc 1918)", $xdata[$i][1]);
       }
       // special case '?? (Not Found) ' => 'unknown'
-      elseif(ereg("[?][?][ \t]+\(Not Found\)[ \t]*", $tmp, $substring))
+      elseif(preg_match("/[?][?][ \t]+\(Not Found\)[ \t]*/", $tmp, $substring))
       {
         $Dataset->addPoint("unknown", $xdata[$i][1]);
       }
       // anything inside parentheses, following a 2-letter TLD:
-      elseif (ereg("^[-a-zA-Z0-9]{2}[ \t]\((.+)\)[ \t]*$", $tmp, $substring))
+      elseif (preg_match("/^[-a-zA-Z0-9]{2}[ \t]\((.+)\)[ \t]*$/", $tmp, $substring))
       {
         $Dataset->addPoint($substring[1], $xdata[$i][1]);
       }
       // anything after two-letter top level domain names and after one space or tab:
-      elseif (ereg("[ \t]*[-a-zA-Z0-9]{2}[ \t]([-a-zA-Z0-9]+[-a-zA-Z0-9 ]*)", $tmp, $substring))
+      elseif (preg_match("/[ \t]*[-a-zA-Z0-9]{2}[ \t]([-a-zA-Z0-9]+[-a-zA-Z0-9 ]*)/", $tmp, $substring))
       {
         $Dataset->addPoint($substring[1], $xdata[$i][1]);
       }
       // two-letter top level domain names right at the beginning:
-      elseif (ereg("[ \t]*([-a-zA-Z0-9]{2})[ \t]", $tmp_lower, $substring))
+      elseif (preg_match("/[ \t]*([-a-zA-Z0-9]{2})[ \t]/", $tmp_lower, $substring))
       {
         $Dataset->addPoint($substring[1], $xdata[$i][1]);
       }
