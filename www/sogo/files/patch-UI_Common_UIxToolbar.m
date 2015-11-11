--- UI/Common/UIxToolbar.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Common/UIxToolbar.m
@@ -166,7 +166,7 @@
     [self errorWithFormat:
             @"not toolbar configuration found on SoObject: %@ (%@)",
             [self clientObject], [[self clientObject] soClass]];
-    toolbarConfig = [[NSNull null] retain];
+    toolbarConfig = (NSArray *)[[NSNull null] retain];
     return nil;
   }
 
