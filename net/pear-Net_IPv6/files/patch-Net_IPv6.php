--- Net/IPv6.php.orig	2016-08-31 14:11:53 UTC
+++ Net/IPv6.php
@@ -550,7 +550,7 @@ class Net_IPv6
 
         if (false !== strpos($uip, '::') ) {
 
-            list($ip1, $ip2) = explode('::', $uip);
+            list($ip1, $ip2) = explode('::', $uip, 2);
 
             if ("" == $ip1) {
 
@@ -601,12 +601,12 @@ class Net_IPv6
 
             } else if (-1 == $c1) {              // ::xxx
 
-                $fill = str_repeat('0:', 7-$c2);
+                $fill = str_repeat('0:', max(1, 7-$c2));
                 $uip  = str_replace('::', $fill, $uip);
 
             } else if (-1 == $c2) {              // xxx::
 
-                $fill = str_repeat(':0', 7-$c1);
+                $fill = str_repeat(':0', max(1, 7-$c1));
                 $uip  = str_replace('::', $fill, $uip);
 
             } else {                          // xxx::xxx
@@ -912,7 +912,7 @@ class Net_IPv6
 
             }
 
-            if (8 == $count) {
+            if (8 == $count and empty($ipPart[1])) {
 
                 return true;
 
