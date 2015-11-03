--- UI/MailPartViewers/UIxMailPartViewer.m.orig	2015-09-16 18:41:36 UTC
+++ UI/MailPartViewers/UIxMailPartViewer.m
@@ -270,7 +270,7 @@
   if ([filename length])
     // We replace any slash by a dash since Apache won't allow encoded slashes by default.
     // See http://httpd.apache.org/docs/2.2/mod/core.html#allowencodedslashes
-    filename = [filename stringByReplacingString: @"/" withString: @"-"];
+    filename = [[filename stringByReplacingString: @"/" withString: @"-"] mutableCopy];
   else
     [filename appendFormat: @"%@-%@",
 	      [self labelForKey: @"Untitled"],
