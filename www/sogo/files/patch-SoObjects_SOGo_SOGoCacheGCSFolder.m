--- SoObjects/SOGo/SOGoCacheGCSFolder.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/SOGoCacheGCSFolder.m
@@ -364,7 +364,7 @@ Class SOGoCacheGCSObjectK = Nil;
   if (record)
     {
       if ([[record objectForKey: @"c_type"] intValue] == MAPIFolderCacheObject)
-        objectClass = isa;
+        objectClass = object_getClass(self);
       else
         objectClass = SOGoCacheGCSObjectK;
 
