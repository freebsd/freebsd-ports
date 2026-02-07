--- TextBlock.pm.orig	1999-08-11 14:04:36 UTC
+++ TextBlock.pm
@@ -54,7 +54,7 @@ sub numElements {
     # Returns the number of elements in the TextBlock
     #
     my $self = shift;
-    return $#{@$self}+1;
+    return scalar(@$self);
 }
 
 sub Write {
