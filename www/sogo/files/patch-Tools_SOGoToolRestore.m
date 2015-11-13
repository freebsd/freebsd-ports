--- Tools/SOGoToolRestore.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolRestore.m
@@ -574,6 +574,7 @@
           NSLog (@"  %@ (%@)",
                  folderKey, [currentFolder objectForKey: @"displayname"]);
         }
+      rc = YES;
     }
   else
     {
