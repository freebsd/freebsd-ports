--- UI/Scheduler/UIxCalDayView.m.orig	2015-09-16 18:41:32 UTC
+++ UI/Scheduler/UIxCalDayView.m
@@ -164,7 +164,7 @@
     
   date = [self selectedDate];
   hmString = [NSString stringWithFormat:@"%.2d%.2d",
-                       [date hourOfDay], [date minuteOfHour]];
+                       (int)[date hourOfDay], (int)[date minuteOfHour]];
   qp = [[self queryParameters] mutableCopy];
   [self setSelectedDateQueryParameter:date inDictionary:qp];
   [qp setObject: hmString forKey:@"hm"];
