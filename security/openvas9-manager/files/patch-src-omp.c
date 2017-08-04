--- src/omp.c	2017-06-21 04:56:09.000000000 -0500
+++ src/omp.c	2017-07-28 23:49:52.393994000 -0500
@@ -18078,11 +18078,11 @@
             "<timezone_abbrev>%s</timezone_abbrev>",
             iso,
             (next_time == 0 ? "over" : iso_time_tz (&next_time, timezone, NULL)),
-            schedule_iterator_period (&schedules),
-            schedule_iterator_period_months (&schedules),
+            (long) schedule_iterator_period (&schedules),
+            (long) schedule_iterator_period_months (&schedules),
             simple_period,
             simple_period_unit,
-            schedule_iterator_duration (&schedules),
+            (long) schedule_iterator_duration (&schedules),
             simple_duration,
             simple_duration_unit,
             schedule_iterator_timezone (&schedules)
