--- UI/MailPartViewers/UIxMailPartHTMLViewer.m.orig	2015-09-16 18:41:31 UTC
+++ UI/MailPartViewers/UIxMailPartHTMLViewer.m
@@ -551,9 +551,9 @@ static NSData* _sanitizeContent(NSData *
                   else
                     skipAttribute = YES;
                 }
-              else if ([name isEqualToString: @"background"] ||
+              else if (([name isEqualToString: @"background"] ||
                        ([name isEqualToString: @"data"]
-                        || [name isEqualToString: @"classid"])
+                        || [name isEqualToString: @"classid"]))
                        && [lowerName isEqualToString: @"object"])
                 {
                   value = [_attributes valueAtIndex: count];
@@ -741,7 +741,7 @@ static NSData* _sanitizeContent(NSData *
 
 /* SaxLexicalHandler */
 - (void) comment: (unichar *) _chars
-          length: (NSUInteger) _len
+          length: (int) _len
 {
   showWhoWeAre();
   if (inStyle)
@@ -807,7 +807,7 @@ static NSData* _sanitizeContent(NSData *
     }
   [dump appendFormat: @"--- end ---\n"];
 
-  NSLog(dump);
+  NSLog(@"%@", dump);
   [dump release];
 }
 
