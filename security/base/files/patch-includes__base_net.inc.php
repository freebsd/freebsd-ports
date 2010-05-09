--- ./includes/base_net.inc.php.orig	2010-03-05 16:06:18.000000000 +0100
+++ ./includes/base_net.inc.php	2010-04-11 23:52:13.000000000 +0200
@@ -391,7 +391,7 @@
         $line = explode(" ", $response_l[$i]);
         for ($j=0; $j < sizeof($line); $j++ )
         {
-          if ( eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$", $line[$j]) )
+          if ( preg_match("/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/i", $line[$j]) )
           {
              if ( $email == "" )
                 $email = $line[$j];
