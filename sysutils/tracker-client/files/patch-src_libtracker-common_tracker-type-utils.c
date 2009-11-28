--- src/libtracker-common/tracker-type-utils.c.orig	2009-08-08 17:29:36.000000000 +0000
+++ src/libtracker-common/tracker-type-utils.c	2009-08-08 17:30:09.000000000 +0000
@@ -531,8 +531,8 @@
 	/* mktime() always assumes that "tm" is in locale time but we
 	 * want to keep control on time, so we go to UTC
 	 */
-	t  = mktime (&tm);
-	t -= timezone;
+
+	t = timegm (&tm);
 
 	if (*date_string == '+' ||
 	    *date_string == '-') {
