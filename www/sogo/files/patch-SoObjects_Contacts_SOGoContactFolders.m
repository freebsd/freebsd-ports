--- SoObjects/Contacts/SOGoContactFolders.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Contacts/SOGoContactFolders.m
@@ -268,9 +268,9 @@ Class SOGoContactSourceFolderK;
   SOGoUser *currentUser;
   id <SOGoSource> source;
 
-  if ([sourceID isEqualToString: @"personal"])
-    result = [NSException exceptionWithHTTPStatus: 403
-                                           reason: (@"folder '%@' cannot be deleted", sourceID)];
+  if ([sourceID isEqualToString: @"personal"]){
+    result = [NSException exceptionWithHTTPStatus: 403 reason: [NSString stringWithFormat: (@"folder '%@' cannot be deleted"), sourceID]];
+  }
   else
     {
       result = nil;
