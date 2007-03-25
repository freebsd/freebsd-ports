--- asclock.h.orig	Fri Mar 26 15:49:34 1999
+++ asclock.h	Sun Mar 25 13:08:41 2007
@@ -76,12 +76,12 @@
 GdkColormap *cmap;
 
 /* the xpm data */
-extern char *clock_xpm[];
-extern char *month_xpm[];
-extern char *weekday_xpm[];
-extern char *led_xpm[];
+static char *clock_xpm[];
+static char *month_xpm[];
+static char *weekday_xpm[];
+static char *led_xpm[];
 extern char *beats_xpm[];
-extern char *date_xpm[];
+static char *date_xpm[];
 extern char *hour_xpm[];
 extern char *minute_xpm[];
 extern char *second_xpm[];
