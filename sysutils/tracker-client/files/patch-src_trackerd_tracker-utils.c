--- src/trackerd/tracker-utils.c.orig	2007-08-05 01:53:12.000000000 +0400
+++ src/trackerd/tracker-utils.c	2007-08-24 22:31:05.000000000 +0400
@@ -727,10 +727,7 @@
 		tm.tm_sec = strtoul (timestamp, (char **)&timestamp, 10);
 	}
 
-	tt = mktime (&tm);
-        /* mktime() always assumes that "tm" is in locale time but
-           we want to keep control on time, so we go to UTC */
-        tt -= timezone;
+	tt = timegm (&tm);
 
 	if (*timestamp == '+' || *timestamp == '-') {
 		int sign;
