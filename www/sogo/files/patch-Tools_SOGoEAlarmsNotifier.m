--- Tools/SOGoEAlarmsNotifier.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoEAlarmsNotifier.m
@@ -81,8 +81,8 @@
   timestamp = (int) [[NSDate date] timeIntervalSince1970];
   pGUID = [[NSProcessInfo processInfo] globallyUniqueString];
 
-  messageID = [NSString stringWithFormat: @"<%0X-%0X-%0X-%0X@%u>",
-                        pid, timestamp, sequence, random(), [pGUID hash]];
+  messageID = [NSString stringWithFormat: @"<%0X-%0X-%0X-%0X@%lu>",
+                        pid, timestamp, sequence, (unsigned int)random(), [pGUID hash]];
 
   return [messageID lowercaseString];
 }
