--- UI/MailerUI/UIxMailMainFrame.m.orig	2015-09-16 18:41:36 UTC
+++ UI/MailerUI/UIxMailMainFrame.m
@@ -627,7 +627,7 @@
 
 - (NSString *) columnsDisplayCount
 {
-  return [NSString stringWithFormat: @"%d", [[self columnsDisplayOrder] count]];
+  return [NSString stringWithFormat: @"%d", (int)[[self columnsDisplayOrder] count]];
 }
 
 - (void) setCurrentColumn: (NSDictionary *) newCurrentColumn
