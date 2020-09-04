--- src/omp.c.orig	2017-06-21 07:16:17 UTC
+++ src/omp.c
@@ -16424,11 +16424,11 @@ omp_xml_handle_end_element (/*@unused@*/ GMarkupParseC
                     "<timezone_abbrev>%s</timezone_abbrev>",
                     iso,
                     (next_time == 0 ? "over" : iso_time_tz (&next_time, timezone, NULL)),
-                    schedule_iterator_period (&schedules),
-                    schedule_iterator_period_months (&schedules),
+                    (long) schedule_iterator_period (&schedules),
+                    (long) schedule_iterator_period_months (&schedules),
                     simple_period,
                     simple_period_unit,
-                    schedule_iterator_duration (&schedules),
+                    (long) schedule_iterator_duration (&schedules),
                     simple_duration,
                     simple_duration_unit,
                     schedule_iterator_timezone (&schedules)
