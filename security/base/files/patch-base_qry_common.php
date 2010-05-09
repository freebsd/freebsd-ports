--- ./base_qry_common.php.orig	2010-03-05 16:06:17.000000000 +0100
+++ ./base_qry_common.php	2010-04-11 23:52:13.000000000 +0200
@@ -773,10 +773,10 @@
            }
         }
         /* if have chosen the address type to be both source and destination */
-        if ( ereg("ip_both", $tmp) )
+        if ( preg_match("/ip_both/", $tmp) )
         {
-           $tmp_src = ereg_replace("ip_both","ip_src",$tmp);
-           $tmp_dst = ereg_replace("ip_both","ip_dst",$tmp);
+           $tmp_src = preg_replace("/ip_both/","ip_src",$tmp);
+           $tmp_dst = preg_replace("/ip_both/","ip_dst",$tmp);
            
            if ( $ip_addr[$i][2] == '=' )
              $tmp = "(".$tmp_src.') OR ('.$tmp_dst.')';
