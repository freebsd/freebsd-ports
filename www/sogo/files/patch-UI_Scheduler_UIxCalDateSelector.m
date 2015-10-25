--- UI/Scheduler/UIxCalDateSelector.m.orig	2015-09-16 18:41:32 UTC
+++ UI/Scheduler/UIxCalDateSelector.m
@@ -117,7 +117,7 @@
 
   date = [self startDate];
 
-  return [NSString stringWithFormat: @"%.2d", [date monthOfYear]];
+  return [NSString stringWithFormat: @"%.2d", (int)[date monthOfYear]];
 }
 
 - (NSString *) headerMonthString
@@ -136,7 +136,7 @@
 
   date = [self startDate];
 
-  return [NSString stringWithFormat: @"%d", [date yearOfCommonEra]];
+  return [NSString stringWithFormat: @"%d", (int)[date yearOfCommonEra]];
 }
 
 - (NSString *) localizedDayOfWeekName
