--- libfreerdp/locale/timezone.c.orig	2013-07-10 19:00:21.000000000 +1100
+++ libfreerdp/locale/timezone.c	2014-01-08 03:32:36.919691015 +1100
@@ -1663,7 +1663,10 @@
 	local_time = localtime(&t);
 
 #ifdef HAVE_TM_GMTOFF
-    clientTimeZone->bias = timezone / 60;
+  if (local_time->tm_gmtoff >= 0)
+    clientTimeZone->bias = (UINT32) (local_time->tm_gmtoff / 60);
+  else
+    clientTimeZone->bias = (UINT32) (1440 + (INT32) (local_time->tm_gmtoff / 60));
 	DEBUG_TIMEZONE("tzname[std]: %s, tzname[dst]: %s, timezone: %ld, Daylight: %d", tzname[0], tzname[1], timezone, daylight);
 #elif defined(sun)
 	if (local_time->tm_isdst > 0)
