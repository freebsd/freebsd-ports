--- SoObjects/SOGo/SOGoFolder.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoFolder.m
@@ -107,7 +107,7 @@
 
 - (void) setDisplayName: (NSString *) newDisplayName
 {
-  ASSIGN (displayName, newDisplayName);
+  ASSIGN (displayName, [newDisplayName mutableCopy]);
 }
 
 - (NSString *) displayName
