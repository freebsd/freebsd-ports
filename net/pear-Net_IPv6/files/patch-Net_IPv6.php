--- Net/IPv6.php.orig	2018-07-09 11:55:41 UTC
+++ Net/IPv6.php
@@ -853,10 +853,10 @@ class Net_IPv6
                 return array("", $ip);
             }
 
-            $ip{$pos} = '_';
+            $ip[$pos] = '_';
             $ipPart   = explode('_', $ip);
             
-            if ($ip{$pos-1} === ":") {
+            if ($ip[$pos-1] === ":") {
                 $ipPart[0] .= ":";
             }
 
