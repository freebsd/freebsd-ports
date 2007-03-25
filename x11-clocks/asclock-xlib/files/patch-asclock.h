--- asclock.h.orig	Sun Mar 25 12:58:29 2007
+++ asclock.h	Sun Mar 25 12:59:09 2007
@@ -38,11 +38,11 @@
 #define INT_TYPE 0;
 
 /* the xpm data */
-extern char *clock_xpm[];
-extern char *month_xpm[];
-extern char *weekday_xpm[];
-extern char *led_xpm[];
-extern char *date_xpm[];
+static char *clock_xpm[];
+static char *month_xpm[];
+static char *weekday_xpm[];
+static char *led_xpm[];
+static char *date_xpm[];
 extern char *hour_xpm[];
 extern char *minute_xpm[];
 extern char *second_xpm[];
