--- head.c.orig	2006-03-03 16:01:19.000000000 -0800
+++ head.c	2022-01-26 18:13:57.270492000 -0800
@@ -1116,10 +1116,8 @@
 	if ((t = combinetime(year, month, day, hour, minute, second)) ==
 			(time_t)-1)
 		goto invalid;
-	tzdiff = t - mktime(gmtime(&t));
 	tmptr = localtime(&t);
-	if (tmptr->tm_isdst > 0)
-		tzdiff += 3600;
+	tzdiff = tmptr->tm_gmtoff; /* seconds east of GMT */
 	t -= tzdiff;
 	return t;
 invalid:
