--- sendout.c.orig	2008-07-03 23:09:57.000000000 -0700
+++ sendout.c	2022-01-26 18:25:05.091791000 -0800
@@ -885,6 +885,7 @@
 				cp = expand(cp);
 			else
 				cp = SENDMAIL;
+			args[0] = cp;
 			execv(cp, args);
 			perror(cp);
 		}
@@ -1123,9 +1124,7 @@
 
 /*
  * Create a Date: header field.
- * We compare the localtime() and gmtime() results to get the timezone,
- * because numeric timezones are easier to read and because $TZ is
- * not set on most GNU systems.
+ * We use tm->tm_gmtoff to account for negative DST adjustments (e.g. Ireland).
  */
 int
 mkdate(FILE *fo, const char *field)
@@ -1135,13 +1134,11 @@
 	int tzdiff, tzdiff_hour, tzdiff_min;
 
 	time(&t);
-	tzdiff = t - mktime(gmtime(&t));
+	tmptr = localtime(&t);
+	tzdiff = tmptr->tm_gmtoff; /* seconds east of GMT */
 	tzdiff_hour = (int)(tzdiff / 60);
 	tzdiff_min = tzdiff_hour % 60;
 	tzdiff_hour /= 60;
-	tmptr = localtime(&t);
-	if (tmptr->tm_isdst > 0)
-		tzdiff_hour++;
 	return fprintf(fo, "%s: %s, %02d %s %04d %02d:%02d:%02d %+05d\n",
 			field,
 			weekday_names[tmptr->tm_wday],
