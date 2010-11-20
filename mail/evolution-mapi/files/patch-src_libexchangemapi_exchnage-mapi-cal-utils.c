--- src/libexchangemapi/exchange-mapi-cal-utils.c.orig	2010-06-07 16:59:16.000000000 +0200
+++ src/libexchangemapi/exchange-mapi-cal-utils.c	2010-06-07 17:01:25.000000000 +0200
@@ -2175,6 +2175,7 @@ populate_freebusy_data (struct Binary_r 
 	gchar *start = NULL, *end = NULL;
 	time_t start_date, end_date;
 	icalcomponent *icalcomp = NULL;
+	int daylight = 0;
 
 	if (!bin)
 		return;
