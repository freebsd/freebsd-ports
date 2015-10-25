--- UI/Contacts/UIxContactActions.m.orig	2015-09-16 18:41:31 UTC
+++ UI/Contacts/UIxContactActions.m
@@ -141,7 +141,7 @@
   content = [NSMutableString string];
   response = [context response];
 
-  [content appendFormat: [[self clientObject] contentAsString]];
+  [content appendFormat: @"%@", [[self clientObject] contentAsString]];
   [response setHeader: @"text/plain; charset=utf-8" 
             forKey: @"content-type"];
   [response appendContentString: content];
