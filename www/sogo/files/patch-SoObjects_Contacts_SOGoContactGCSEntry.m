--- SoObjects/Contacts/SOGoContactGCSEntry.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Contacts/SOGoContactGCSEntry.m
@@ -50,7 +50,7 @@
 
 - (Class *) parsingClass
 {
-  return [NGVCard class];
+  return (Class *)[NGVCard class];
 }
 
 /* content */
