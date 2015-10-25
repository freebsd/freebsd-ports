--- SoObjects/Appointments/SOGoCalendarComponent.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Appointments/SOGoCalendarComponent.m
@@ -140,6 +140,13 @@
   return aclManager;
 }
 
+- (NSException *) changeParticipationStatus: (NSString *) newPartStat
+                               withDelegate: (iCalPerson *) delegate
+                                      alarm: (iCalAlarm *) alarm;
+{
+  return nil;
+}
+
 - (id) init
 {
   if ((self = [super init]))
@@ -171,7 +178,7 @@
 
 - (Class *) parsingClass
 {
-  return [iCalCalendar class];
+  return (Class *) [iCalCalendar class];
 }
 
 - (NSString *) davContentType
