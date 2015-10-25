--- SoObjects/Mailer/SOGoMailForward.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Mailer/SOGoMailForward.m
@@ -73,10 +73,10 @@
 
 - (NSString *) newLine
 {
-  NSString *rc = [NSString stringWithString: @" "];
+  NSString *rc = @" ";
   
   if (htmlComposition)
-    rc = [NSString stringWithString: @"<br/>"];
+    rc = @"<br/>";
 
   return rc;
 }
