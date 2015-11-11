--- SoObjects/Contacts/SOGoContactSourceFolder.m.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Contacts/SOGoContactSourceFolder.m
@@ -94,7 +94,7 @@
     {
       if (![newDisplayName length])
         newDisplayName = newName;
-      ASSIGN (displayName, newDisplayName);
+      ASSIGN (displayName, [newDisplayName mutableCopy]);
     }
 
   return self;
@@ -657,7 +657,7 @@
   BOOL otherIsPersonal;
 
   otherIsPersonal = ([otherFolder isKindOfClass: [SOGoContactGCSFolder class]]
-                     || ([otherFolder isKindOfClass: isa] && [otherFolder isPersonalSource]));
+                     || ([otherFolder isKindOfClass: object_getClass(self)] && [otherFolder isPersonalSource]));
 
   if (isPersonalSource)
     {
