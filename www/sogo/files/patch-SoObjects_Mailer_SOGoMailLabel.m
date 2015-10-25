--- SoObjects/Mailer/SOGoMailLabel.m.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Mailer/SOGoMailLabel.m
@@ -74,7 +74,7 @@
   int i;
 
   allLabels = [NSMutableArray array];
-  allKeys = [[theDefaults allKeys] sortedArrayUsingSelector: @selector (caseInsensitiveCompare:)];
+  allKeys = [[[theDefaults allKeys] sortedArrayUsingSelector: @selector (caseInsensitiveCompare:)] mutableCopy];
   
   for (i = 0; i < [allKeys count]; i++)
     {
