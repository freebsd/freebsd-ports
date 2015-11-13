--- SoObjects/SOGo/SOGoGCSFolder.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoGCSFolder.m
@@ -376,12 +376,12 @@ static NSArray *childRecordFields = nil;
   if (!displayName)
     {
       if (activeUserIsOwner)
-        displayName = [self _displayNameFromOwner];
+        displayName = [[self _displayNameFromOwner] mutableCopy];
       else
         {
-          displayName = [self _displayNameFromSubscriber];
+          displayName = [[self _displayNameFromSubscriber] mutableCopy];
           if (!displayName)
-            displayName = [self _displayNameFromOwner];
+            displayName = [[self _displayNameFromOwner] mutableCopy];
         }
       [displayName retain];
     }
@@ -829,7 +829,7 @@ static NSArray *childRecordFields = nil;
     {
       currentID = [ids objectAtIndex: count];
       names = [[currentID componentsSeparatedByString: @"/"] objectEnumerator];
-      deleteObject = self;
+      deleteObject = (SOGoContentObject *)self;
       while ((currentName = [names nextObject]))
         {
           deleteObject = [deleteObject lookupName: currentName
