--- wsutil/ws_strptime.c.orig	2023-11-17 16:54:52 UTC
+++ wsutil/ws_strptime.c
@@ -197,9 +197,12 @@ ws_strptime(const char *buf, const char *fmt, struct t
 	    day_offset = -1, week_offset = 0, offs, mandatory;
 	const char *new_fmt;
 	long tm_gmtoff;
+	struct tm *gtm;
+	const time_t zero_secs = 0;
 	const char *tm_zone;
 
 	bp = (const unsigned char *)buf;
+	gtm = localtime(&zero_secs);
 
 	while (bp != NULL && (c = *fmt++) != '\0') {
 		/* Clear `alternate' modifier prior to new conversion. */
@@ -570,7 +573,7 @@ namedzone:
 				}
 				/* 'J' is local time */
 				if (delim(bp[1]) && *bp == 'J') {
-					tm_gmtoff = -timezone;
+					tm_gmtoff = gtm->tm_gmtoff;
 					tm_zone = NULL; /* XXX */
 					SET_ZONEP(zonep, tm_gmtoff, tm_zone);
 					bp++;
@@ -605,7 +608,7 @@ namedzone:
 						 NULL, 2);
 				if (ep != NULL) {
 					tm->tm_isdst = i;
-					tm_gmtoff = -timezone;
+					tm_gmtoff = gtm->tm_gmtoff;
 					tm_zone = tzname[i];
 					SET_ZONEP(zonep, tm_gmtoff, tm_zone);
 					bp = ep;
