--- UI/Contacts/UIxContactFolderActions.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Contacts/UIxContactFolderActions.m
@@ -78,9 +78,9 @@
                                     inContext: [self context]
                                       acquire: NO];
       if ([currentChild respondsToSelector: @selector (vCard)])
-        [content appendFormat: [[currentChild ldifRecord] ldifRecordAsString]];
+        [content appendFormat: @"%@", [[currentChild ldifRecord] ldifRecordAsString]];
       else if ([currentChild respondsToSelector: @selector (vList)])
-        [content appendFormat: [[currentChild vList] ldifString]];
+        [content appendFormat: @"%@", [[currentChild vList] ldifString]];
       [content appendString: @"\n"];
     }
 
