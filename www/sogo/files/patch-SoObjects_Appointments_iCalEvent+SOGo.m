--- SoObjects/Appointments/iCalEvent+SOGo.m.orig	2015-09-16 18:41:36 UTC
+++ SoObjects/Appointments/iCalEvent+SOGo.m
@@ -259,7 +259,7 @@
 
 - (NSTimeInterval) occurenceInterval
 {
-  return [[self endDate] timeIntervalSinceDate: [self startDate]];
+  return (NSTimeInterval) [[self endDate] timeIntervalSinceDate: [self startDate]];
 }
 
 /**
