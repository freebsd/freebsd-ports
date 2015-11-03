--- UI/Scheduler/UIxCalMonthView.m.orig	2015-09-16 18:41:32 UTC
+++ UI/Scheduler/UIxCalMonthView.m
@@ -299,7 +299,7 @@
 
   [classes appendFormat: @"day weekOf%d week%dof%d day%d",
            numberOfWeeks,
-           [weeksToDisplay indexOfObject: currentWeek],
+           (int)[weeksToDisplay indexOfObject: currentWeek],
            numberOfWeeks, dayOfWeek];
   if (realDayOfWeek == 0 || realDayOfWeek == 6)
     [classes appendString: @" weekEndDay"];
