Fix build on GCC older than 4.6.0 which does not allow #pragma GCC diagnostic
inside of functions.

PR: 242693

--- lib/iso9660/iso9660.c.orig	2019-04-13 15:15:15 UTC
+++ lib/iso9660/iso9660.c
@@ -373,12 +373,18 @@ iso9660_set_ltime_with_timezone(const struct tm *p_tm,
 
   if (!p_tm) return;
 
+#if defined(__GNUC__) && __GNUC__ >= 5
+#pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif
   snprintf(_pvd_date, 17,
            "%4.4d%2.2d%2.2d" "%2.2d%2.2d%2.2d" "%2.2d",
            p_tm->tm_year + 1900, p_tm->tm_mon + 1, p_tm->tm_mday,
            p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec,
            0 /* 1/100 secs */ );
+#if defined(__GNUC__) && __GNUC__ >= 5
+#pragma GCC diagnostic pop
+#endif
 
   /* Set time zone in 15-minute interval encoding. */
   pvd_date->lt_gmtoff -= (time_zone / 15);
