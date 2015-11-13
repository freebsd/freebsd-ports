--- SOPE/NGCards/iCalMonthlyRecurrenceCalculator.m.orig	2015-09-16 18:41:29 UTC
+++ SOPE/NGCards/iCalMonthlyRecurrenceCalculator.m
@@ -348,7 +348,7 @@ static inline unsigned iCalDoWForNSDoW (
                   if ([byDayMask occursOnDay: currentWeekDay])
                     {
                       if ([bySetPos containsObject:
-                                      [NSString stringWithFormat: @"%d", currentPos]])
+                                      [NSString stringWithFormat: @"%d", (int)currentPos]])
                         monthDays[monthDay+1] = YES;
                       currentPos++;
                     }
@@ -362,7 +362,7 @@ static inline unsigned iCalDoWForNSDoW (
                   if ([byDayMask occursOnDay: currentWeekDay])
                     {
                       if ([bySetPos containsObject:
-                                      [NSString stringWithFormat: @"%d", currentPos]])
+                                      [NSString stringWithFormat: @"%d", (int)currentPos]])
                         monthDays[monthDay] = YES;
                       currentPos--;
                     }
