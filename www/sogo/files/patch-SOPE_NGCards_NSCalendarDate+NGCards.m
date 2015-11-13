--- SOPE/NGCards/NSCalendarDate+NGCards.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/NGCards/NSCalendarDate+NGCards.m
@@ -32,16 +32,16 @@
 - (NSString *) iCalFormattedDateTimeString
 {
   return [NSString stringWithFormat: @"%.4d%.2d%.2dT%.2d%.2d%.2d",
-                   [self yearOfCommonEra], [self monthOfYear],
-                   [self dayOfMonth], [self hourOfDay],
-                   [self minuteOfHour], [self secondOfMinute]];
+                   (int)[self yearOfCommonEra], (int)[self monthOfYear],
+                   (int)[self dayOfMonth], (int)[self hourOfDay],
+                   (int)[self minuteOfHour], (int)[self secondOfMinute]];
 }
 
 - (NSString *) iCalFormattedDateString
 {
   return [NSString stringWithFormat: @"%.4d%.2d%.2d",
-                   [self yearOfCommonEra], [self monthOfYear],
-                   [self dayOfMonth]];
+                   (int)[self yearOfCommonEra], (int)[self monthOfYear],
+                   (int)[self dayOfMonth]];
 }
 
 @end
