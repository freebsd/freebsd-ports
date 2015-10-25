--- SoObjects/Appointments/iCalAlarm+SOGo.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Appointments/iCalAlarm+SOGo.m
@@ -102,9 +102,9 @@
         }
       
       if ([reminderReference caseInsensitiveCompare: @"BEFORE"] == NSOrderedSame)
-        aValue = [NSString stringWithString: @"-P"];
+        aValue = (NSString *) @"-P";
       else
-        aValue = [NSString stringWithString: @"P"];
+        aValue = (NSString *) @"P";
       
       if ([reminderUnit caseInsensitiveCompare: @"MINUTES"] == NSOrderedSame ||
           [reminderUnit caseInsensitiveCompare: @"HOURS"] == NSOrderedSame)
