--- lib/ipmi_time.c.orig	2024-09-19 15:25:36 UTC
+++ lib/ipmi_time.c
@@ -105,7 +105,6 @@ ipmi_strftime(char *s, size_t max, const char *format,
 		 * the timezone offset.
 		 */
 		gmtime_r(&stamp, &tm);
-		daylight = -1;
 	} else {
 		/*
 		 * The user wants the time reported in local time zone.
