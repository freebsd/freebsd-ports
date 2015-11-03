--- UI/Contacts/UIxContactView.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Contacts/UIxContactView.m
@@ -350,7 +350,7 @@
   data = [NSMutableString string];
   [data appendString: postalCode];
   if ([postalCode length] > 0 && [country length] > 0)
-    [data appendFormat: @", ", country];
+    [data appendFormat: @", "];
   [data appendString: country];
 
   return [self _cardStringWithLabel: nil value: data];
@@ -562,7 +562,7 @@
   data = [NSMutableString string];
   [data appendString: postalCode];
   if ([postalCode length] > 0 && [country length] > 0)
-    [data appendFormat: @" ", country];
+    [data appendFormat: @", "];
   [data appendString: country];
 
   return [self _cardStringWithLabel: nil value: data];
