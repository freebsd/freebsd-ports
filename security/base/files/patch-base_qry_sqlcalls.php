--- ./base_qry_sqlcalls.php.orig	2010-03-05 16:06:17.000000000 +0100
+++ ./base_qry_sqlcalls.php	2010-04-11 23:52:13.000000000 +0200
@@ -259,9 +259,9 @@
            $line = split (" ", $current_sig_txt);
            foreach ($line as $ps_element) 
            {
-             if ( ereg("[0-9]*\.[0-9]*\.[0-9]*\.[0-9]", $ps_element)  )
+             if ( preg_match("/[0-9]*\.[0-9]*\.[0-9]*\.[0-9]/", $ps_element)  )
              {
-                $ps_element = ereg_replace (":", "", $ps_element);
+                $ps_element = preg_replace ("/:/", "", $ps_element);
                 qroPrintEntry("<A HREF=\"base_stat_ipaddr.php?ip=".$ps_element."&amp;netmask=32\">".
                               $ps_element."</A>");
              }
