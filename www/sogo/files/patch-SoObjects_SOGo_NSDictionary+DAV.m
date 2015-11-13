--- SoObjects/SOGo/NSDictionary+DAV.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/NSDictionary+DAV.m
@@ -46,7 +46,7 @@
 {
   NSString *newTag;
 
-  newTag = [NSString stringWithFormat: @"n%d", [namespaces count]];
+  newTag = [NSString stringWithFormat: @"n%d", (int)[namespaces count]];
   [namespaces setObject: newTag forKey: newNS];
 
   return newTag;
