--- SoObjects/Contacts/SOGoContactGCSList.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Contacts/SOGoContactGCSList.m
@@ -45,7 +45,7 @@
 
 - (Class *) parsingClass
 {
-  return [NGVList class];
+  return (Class *)[NGVList class];
 }
 
 
