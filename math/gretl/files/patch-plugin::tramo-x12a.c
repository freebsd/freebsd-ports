--- plugin/tramo-x12a.c.orig	Tue Feb 18 05:20:25 2003
+++ plugin/tramo-x12a.c	Sun May  4 03:27:36 2003
@@ -187,7 +187,7 @@
     else strcpy(seats, "seats");
 }
 
-static void truncate (char *str, int n)
+static void truncate_ (char *str, int n)
 {
     int len = strlen(str);
 
@@ -361,11 +361,11 @@
     /* formulate name of new variable to add */
     strcpy(varname, pdinfo->varname[0]);
     if (opt == TRAMO_SEATS) {
-	truncate(varname, 5);
+	truncate_(varname, 5);
 	strcat(varname, "_");
 	strncat(varname, tramo_series_strings[code], 2);
     } else {
-	truncate(varname, 4);
+	truncate_(varname, 4);
 	strcat(varname, "_");
 	strcat(varname, x12a_series_strings[code]);
     }
