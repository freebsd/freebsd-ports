--- dates.c.orig	Fri Apr  2 09:08:14 2004
+++ dates.c	Fri Apr  2 09:17:53 2004
@@ -297,8 +297,13 @@
 	if (year >= 0)			date->tm_year = year;
 	while ((year < 0) and (date->tm_year < (2500-1900)) and
 	       (DaysBetween (&today, date) < 0))
-	    if (month < 0)
-		date->tm_mon = (date->tm_mon + 1) % 12;
+	    if (month < 0) {
+		date->tm_mon++;
+		if (date->tm_mon > 11) {
+		    date->tm_mon = 0;
+		    date->tm_year++;
+		}
+	    }
 	    else
 		date->tm_year++;
     } else
