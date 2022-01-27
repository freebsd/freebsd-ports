--- imap.c.orig	2008-01-06 14:46:50.000000000 -0800
+++ imap.c	2022-01-26 18:13:57.271602000 -0800
@@ -3506,10 +3506,8 @@
 		return -1;
 	if ((t = combinetime(year, month, day, 0, 0, 0)) == (time_t)-1)
 		return -1;
-	tzdiff = t - mktime(gmtime(&t));
 	tmptr = localtime(&t);
-	if (tmptr->tm_isdst > 0)
-		tzdiff += 3600;
+	tzdiff = tmptr->tm_gmtoff; /* seconds east of GMT */
 	t -= tzdiff;
 	return t;
 }
@@ -3521,13 +3519,11 @@
 	struct tm	*tmptr;
 	int	tzdiff, tzdiff_hour, tzdiff_min;
 
-	tzdiff = t - mktime(gmtime(&t));
+	tmptr = localtime(&t);
+	tzdiff = tmptr->tm_gmtoff; /* seconds east of GMT */
 	tzdiff_hour = (int)(tzdiff / 60);
 	tzdiff_min = tzdiff_hour % 60;
 	tzdiff_hour /= 60;
-	tmptr = localtime(&t);
-	if (tmptr->tm_isdst > 0)
-		tzdiff_hour++;
 	snprintf(s, sizeof s, "\"%02d-%s-%04d %02d:%02d:%02d %+03d%02d\"",
 			tmptr->tm_mday,
 			month_names[tmptr->tm_mon],
