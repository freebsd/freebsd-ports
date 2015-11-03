--- SoObjects/Appointments/iCalEvent+SOGo.h.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Appointments/iCalEvent+SOGo.h
@@ -28,7 +28,7 @@
 @interface iCalEvent (SOGoExtensions)
 
 - (BOOL) isStillRelevant;
-- (unsigned int) occurenceInterval;
+- (NSTimeInterval) occurenceInterval;
 - (void) updateRecurrenceRulesUntilDate: (NSCalendarDate *) previousEndDate;
 
 @end
