--- ping.php.orig	Wed Nov 21 23:17:27 2001
+++ ping.php	Sun Dec 30 22:05:49 2001
@@ -26,7 +26,7 @@
         $results .= "<br />$ping[$i]\n";
     } 
 } else {
-    exec("/bin/ping -c 5 \"$addr\"", $ping);
+    exec("/sbin/ping -c 5 \"$addr\"", $ping);
     
     for ($i = 0; $i < count($ping); $i++) {
         $results .= "<br />$ping[$i]\n";
