--- calendarfunc.h.orig	2009-01-26 19:19:55.000000000 +0100
+++ calendarfunc.h	2009-01-26 19:20:13.000000000 +0100
@@ -22,7 +22,7 @@
 
 #include <unistd.h>
 #include <stdlib.h>
-#include <ical.h>
+#include <libical/ical.h>
 #define TIMZ 3.0
 #define MINAGE 13.5
 #define SUNSET 19.5 /*approximate */
