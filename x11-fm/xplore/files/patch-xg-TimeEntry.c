--- xg/TimeEntry.c.orig	Wed May  1 16:59:23 2002
+++ xg/TimeEntry.c	Wed Dec 17 22:48:28 2003
@@ -1549,7 +1549,7 @@
 {
 struct tm	ts;
 long		time_value;
-#ifdef __OpenBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 extern long tz;
 #else
 extern long timezone;
@@ -1578,7 +1578,7 @@
 	 */
 	if ( te->timeentry.use_timezone == False )
 	{
-#ifdef __OpenBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		time_value -= tz;
 #else
 		time_value -= timezone;
