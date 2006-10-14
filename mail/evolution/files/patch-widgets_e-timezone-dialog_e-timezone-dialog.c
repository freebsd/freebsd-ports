--- widgets/e-timezone-dialog/e-timezone-dialog.c.orig	Mon Jul 10 21:50:12 2006
+++ widgets/e-timezone-dialog/e-timezone-dialog.c	Mon Jul 10 22:11:54 2006
@@ -80,7 +80,9 @@ struct _ETimezoneDialogPrivate {
 
 #ifndef G_OS_WIN32 /* Declared properly in time.h already */
 extern char *tzname[2];
+#ifndef __BSD_VISIBLE
 extern long timezone;
+#endif
 extern int daylight;
 #endif
 
@@ -317,9 +319,20 @@ static const icaltimezone*
 get_local_timezone()
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
