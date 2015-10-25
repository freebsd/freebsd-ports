--- Tests/Unit/TestiCalTimeZonePeriod.m.orig	2015-09-16 18:41:31 UTC
+++ Tests/Unit/TestiCalTimeZonePeriod.m
@@ -80,8 +80,8 @@
       testWithMessage ((NSInteger) [testDate timeIntervalSince1970]
                        == occurrenceSeconds[count],
                        ([NSString stringWithFormat:
-                                    @"test %d: seconds do not match:"
-                                  @" delta = %d", count, delta]));
+                                    @"test %ld: seconds do not match:"
+                                  @" delta = %ld", count, delta]));
     }
 }
 
