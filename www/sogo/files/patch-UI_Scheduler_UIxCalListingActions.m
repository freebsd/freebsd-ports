--- UI/Scheduler/UIxCalListingActions.m.orig	2015-09-16 18:41:36 UTC
+++ UI/Scheduler/UIxCalListingActions.m
@@ -316,7 +316,7 @@ static NSArray *tasksFields = nil;
   NSString *owner, *role, *calendarName, *filters, *iCalString;
   NSRange match;
   iCalCalendar *calendar;
-  iCalObject *master;
+  iCalEntityObject *master;
   SOGoAppointmentFolder *currentFolder;
   SOGoAppointmentFolders *clientObject;
   SOGoUser *ownerUser;
@@ -350,11 +350,11 @@ static NSArray *tasksFields = nil;
           else if ([criteria isEqualToString:@"entireContent"])
             {
               // First search : Through the quick table inside the location, category and title columns
-              quickInfos = [currentFolder fetchCoreInfosFrom: startDate
+              quickInfos = [[currentFolder fetchCoreInfosFrom: startDate
                                                           to: endDate
                                                        title: value
                                                    component: component
-                                           additionalFilters: criteria];
+                                           additionalFilters: criteria] mutableCopy];
         
               // Save the c_name in another array to compare with
               if ([quickInfos count] > 0)
@@ -366,10 +366,10 @@ static NSArray *tasksFields = nil;
                 }
         
               // Second research : Every objects except for those already in the quickInfos array
-              allInfos = [currentFolder fetchCoreInfosFrom: startDate
+              allInfos = [[currentFolder fetchCoreInfosFrom: startDate
                                                         to: endDate
                                                      title: nil
-                                                 component: component];
+                                                 component: component] mutableCopy];
               if (quickInfosFlag == YES)
                 {
                   for (i = ([allInfos count] - 1); i >= 0 ; i--) {
@@ -383,7 +383,7 @@ static NSArray *tasksFields = nil;
                 {
                   iCalString = [[allInfos objectAtIndex:i] objectForKey:@"c_content"];
                   calendar = [iCalCalendar parseSingleFromSource: iCalString];
-                  master = [calendar firstChildWithTag:component];
+                  master = (iCalEntityObject *)[calendar firstChildWithTag:component];
                   if (master) {
                     if ([[master comment] length] > 0)
                       {
@@ -1089,7 +1089,7 @@ _computeBlocksPosition (NSArray *blocks)
   
   if ([currentView isEqualToString: @"multicolumndayview"])
   {
-    calendars = [self _selectedCalendars];
+    calendars = [[self _selectedCalendars] mutableCopy];
     eventsByCalendars = [NSMutableArray arrayWithCapacity:[calendars count]];
     for (i = 0; i < [calendars count]; i++) // For each calendar
     {
