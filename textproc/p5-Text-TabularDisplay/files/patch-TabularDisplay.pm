--- TabularDisplay.pm.orig	Sun May 16 23:07:02 2004
+++ TabularDisplay.pm	Mon May 17 23:56:08 2004
@@ -240,7 +240,7 @@
 
         push @data, $add->[$i];
         $length->[$i] = $l
-            unless $length->[$i] > $l;
+            unless defined $length->[$i] and $length->[$i] > $l;
     }
     push @$where, \@data;
 }
