--- UI/Scheduler/UIxRecurrenceEditor.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Scheduler/UIxRecurrenceEditor.m
@@ -148,7 +148,7 @@
       [shortWeekDaysList retain];
     }
 
-  id = [NSString stringWithFormat: @"weekDay%i", [shortWeekDaysList indexOfObject: item]];
+  id = [NSString stringWithFormat: @"weekDay%i", (int)[shortWeekDaysList indexOfObject: item]];
 
   return id;
 }
