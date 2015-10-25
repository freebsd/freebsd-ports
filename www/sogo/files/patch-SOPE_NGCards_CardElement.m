--- SOPE/NGCards/CardElement.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/NGCards/CardElement.m
@@ -414,7 +414,7 @@
   if (group)
     [str appendFormat: @"%@ (group: %@)\n", tag, group];
   else
-    [str appendFormat: @"%@\n", tag, group];
+    [str appendFormat: @"%@\n", tag];
 
   [str appendString: [self versitString]];
 
