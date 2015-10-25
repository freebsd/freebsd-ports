--- UI/Scheduler/UIxCalViewPrint.m.orig	2015-09-16 18:41:32 UTC
+++ UI/Scheduler/UIxCalViewPrint.m
@@ -49,6 +49,7 @@ static NSArray *layoutItems = nil;
 - (void) dealloc
 {
   [item release];
+  [super dealloc];
 }
 
 - (void) setItem: (NSString *) newItem
@@ -68,7 +69,7 @@ static NSArray *layoutItems = nil;
 
 - (NSString *) itemPrintLayoutText
 {
-  return [self labelForKey: [NSString stringWithFormat: item]];
+  return [self labelForKey: [NSString stringWithFormat: @"%@", item]];
 }
 
 //
