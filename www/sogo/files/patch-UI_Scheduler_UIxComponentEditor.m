--- UI/Scheduler/UIxComponentEditor.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Scheduler/UIxComponentEditor.m
@@ -2472,7 +2472,7 @@ RANGE(2);
   content = [NSMutableString string];
   response = [context response];
 
-  [content appendFormat: [[self clientObject] contentAsString]];
+  [content appendFormat: @"%@", [[self clientObject] contentAsString]];
   [response setHeader: @"text/plain; charset=utf-8" 
             forKey: @"content-type"];
   [response appendContentString: content];
