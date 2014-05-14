--- src/libexchangemapi/e-mapi-cal-utils.c.orig	2014-03-24 09:28:56.000000000 +0000
+++ src/libexchangemapi/e-mapi-cal-utils.c	2014-05-07 09:56:54.788424673 +0000
@@ -462,6 +462,7 @@
 	gchar *start = NULL, *end = NULL;
 	time_t start_date, end_date;
 	icalcomponent *icalcomp = NULL;
+	int daylight;
 
 	if (!bin)
 		return;
