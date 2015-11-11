--- SOPE/NGCards/iCalRecurrenceRule.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/NGCards/iCalRecurrenceRule.m
@@ -309,10 +309,10 @@ NSString *iCalWeekDayString[] = { @"SU",
       else if ([frequency isEqualToString:@"SECONDLY"])
 	freq = iCalRecurrenceFrequenceSecondly;
       else
-	freq = NSNotFound;
+	freq = (iCalRecurrenceFrequency) NSNotFound;
     }
   else
-    freq = NSNotFound;
+    freq = (iCalRecurrenceFrequency) NSNotFound;
 
   return freq;
 }
