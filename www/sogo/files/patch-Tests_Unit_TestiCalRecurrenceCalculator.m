--- Tests/Unit/TestiCalRecurrenceCalculator.m.orig	2015-09-16 18:41:31 UTC
+++ Tests/Unit/TestiCalRecurrenceCalculator.m
@@ -107,7 +107,7 @@
 			    [currentOccurrence descriptionWithCalendarFormat: dateFormat]];
 	  testWithMessage([currentOccurrence isDateOnSameDay: [[occurrences objectAtIndex: j] startDate]], error);
 	}
-      error = [NSString stringWithFormat: @"Unexpected number of occurrences for recurrence rule %@ (found %i, expected %i)",
+      error = [NSString stringWithFormat: @"Unexpected number of occurrences for recurrence rule %@ (found %ld, expected %ld)",
 			[currentRule objectAtIndex: 1],
 			[occurrences count],
 			[currentRule count] - 2];
@@ -211,7 +211,7 @@
 			    [currentOccurrence descriptionWithCalendarFormat: dateFormat]];
 	  testWithMessage([currentOccurrence isDateOnSameDay: [[occurrences objectAtIndex: j] startDate]], error);
 	}
-      error = [NSString stringWithFormat: @"Unexpected number of occurrences for recurrence rule %@ (found %i, expected %i)",
+      error = [NSString stringWithFormat: @"Unexpected number of occurrences for recurrence rule %@ (found %ld, expected %ld)",
 			[currentRule objectAtIndex: 1],
 			[occurrences count],
 			[currentRule count] - 2];
@@ -376,7 +376,7 @@
 			    [currentOccurrence descriptionWithCalendarFormat: dateFormat]];
 	  testWithMessage([currentOccurrence isDateOnSameDay: [[occurrences objectAtIndex: j] startDate]], error);
 	}
-      error = [NSString stringWithFormat: @"Unexpected number of occurrences for recurrence rule %@ (found %i, expected %i)",
+      error = [NSString stringWithFormat: @"Unexpected number of occurrences for recurrence rule %@ (found %ld, expected %ld)",
 			[currentRule objectAtIndex: 1],
 			[occurrences count],
 			[currentRule count] - 2];
