--- UI/Scheduler/UIxCalDayTable.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Scheduler/UIxCalDayTable.m
@@ -37,6 +37,9 @@
 #import <SOGo/SOGoUserDefaults.h>
 #import <SOGo/WOResourceManager+SOGo.h>
 
+#import <Appointments/SOGoAppointmentFolder.h>
+#import <Appointments/SOGoAppointmentFolders.h>
+
 #import "UIxCalDayTable.h"
 
 @class SOGoAppointment;
@@ -191,7 +194,7 @@
     NSMutableDictionary *calendar;
     unsigned int count, foldersCount;
     NSString *folderName, *fDisplayName;
-    BOOL *isActive;
+    BOOL isActive;
     
     co = [self clientObject];
     folders = [co subFolders];
@@ -200,8 +203,8 @@
     for (count = 0; count < foldersCount; count++)
     {
       folder = [folders objectAtIndex: count];
-      isActive = [NSNumber numberWithBool: [folder isActive]];
-      if ([isActive intValue] != 0) {
+      isActive = [folder isActive];
+      if (isActive != NO) {
         calendar = [NSMutableDictionary dictionary];
         folderName = [folder nameInContainer];
         fDisplayName = [folder displayName];
@@ -214,7 +217,7 @@
         [calendar setObject: fDisplayName forKey: @"displayName"];
         [calendar setObject: folderName forKey: @"folder"];
         [calendar setObject: [folder calendarColor] forKey: @"color"];
-        [calendar setObject: isActive forKey: @"active"];
+        [calendar setObject: [NSNumber numberWithBool:isActive] forKey: @"active"];
         [calendar setObject: [folder ownerInContext: context]
                      forKey: @"owner"];
         [calendarsToDisplay addObject: calendar];
@@ -235,12 +238,12 @@
   return currentTableDay;
 }
 
-- (void) setCurrentCalendar: (NSMutableArray *) aCalendar
+- (void) setCurrentCalendar: (NSMutableDictionary *) aCalendar
 {
   ASSIGN(currentCalendar, aCalendar);
 }
 
-- (NSMutableArray *) currentCalendar
+- (NSMutableDictionary *) currentCalendar
 {
   return currentCalendar;
 }
