--- Tools/SOGoToolCreateFolder.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolCreateFolder.m
@@ -97,7 +97,7 @@
   rc = [self createFolder: folder withFM: fm];
   if (!rc)
     {
-      NSLog (@"Create directory failed at path %s", folder);
+      NSLog (@"Create directory failed at path %@", folder);
       return NO;
     }
 
