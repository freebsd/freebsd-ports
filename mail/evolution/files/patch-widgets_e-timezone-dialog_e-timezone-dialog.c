--- widgets/e-timezone-dialog/e-timezone-dialog.c.orig	2007-11-30 05:24:05.000000000 +0100
+++ widgets/e-timezone-dialog/e-timezone-dialog.c	2007-12-21 16:24:39.000000000 +0100
@@ -82,7 +82,9 @@
 
 #ifndef G_OS_WIN32 /* Declared properly in time.h already */
 extern char *tzname[2];
+#ifndef __BSD_VISIBLE
 extern long timezone;
+#endif
 extern int daylight;
 #endif
 
@@ -326,9 +328,20 @@
 get_local_timezone(void)
 {
 	icaltimezone *zone;
+	long offset;
+#ifdef __BSD_VISIBLE
+	time_t tt;
+	struct tm tm;
+#endif
 
 	tzset();
-	zone =  icaltimezone_get_builtin_timezone_from_offset (-timezone, tzname[0]);
+#ifdef __BSD_VISIBLE
+	localtime_r (&tt, &tm);
+	offset = tm.tm_gmtoff;
+#else
+	offset = -timezone;
+#endif
+	zone =  icaltimezone_get_builtin_timezone_from_offset (offset, tzname[0]);
 
 	return zone;
 }
