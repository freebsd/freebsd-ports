--- libical/src/libical/icaltime.c.orig	Tue Aug 26 20:25:02 2003
+++ libical/src/libical/icaltime.c	Tue Aug 26 20:29:05 2003
@@ -46,6 +46,76 @@
 
 #include "icaltimezone.h"
 
+static time_t make_time(struct tm *tm, int tzm)
+{
+  time_t tim;
+
+  static int days[] = { -1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 364 };
+
+  /* check that year specification within range */
+
+  if (tm->tm_year < 70 || tm->tm_year > 138)
+    return((time_t) -1);
+
+  /* check that month specification within range */
+
+  if (tm->tm_mon < 0 || tm->tm_mon > 11)
+    return((time_t) -1);
+
+  /* check for upper bound of Jan 17, 2038 (to avoid possibility of
+     32-bit arithmetic overflow) */
+  
+  if (tm->tm_year == 138) {
+    if (tm->tm_mon > 0)
+      return((time_t) -1);
+    else if (tm->tm_mday > 17)
+      return((time_t) -1);
+  }
+
+  /*
+   *  calculate elapsed days since start of the epoch (midnight Jan
+   *  1st, 1970 UTC) 17 = number of leap years between 1900 and 1970
+   *  (number of leap days to subtract)
+   */
+
+  tim = (tm->tm_year - 70) * 365 + ((tm->tm_year - 1) / 4) - 17;
+
+  /* add number of days elapsed in the current year */
+
+  tim += days[tm->tm_mon];
+
+  /* check and adjust for leap years (the leap year check only valid
+     during the 32-bit era */
+
+  if ((tm->tm_year & 3) == 0 && tm->tm_mon > 1)
+    tim += 1;
+
+  /* elapsed days to current date */
+
+  tim += tm->tm_mday;
+
+
+  /* calculate elapsed hours since start of the epoch */
+
+  tim = tim * 24 + tm->tm_hour;
+
+  /* calculate elapsed minutes since start of the epoch */
+
+  tim = tim * 60 + tm->tm_min;
+  
+  /* adjust per time zone specification */
+  
+  tim -= tzm;
+  
+  /* calculate elapsed seconds since start of the epoch */
+  
+  tim = tim * 60 + tm->tm_sec;
+  
+  /* return number of seconds since start of the epoch */
+  
+  return(tim);
+}
+
 
 struct icaltimetype 
 icaltime_from_timet(time_t tm, int is_date)
@@ -221,13 +291,7 @@
     stm.tm_year = tt.year-1900;
     stm.tm_isdst = -1;
 
-    if(tt.is_utc == 1 || tt.is_date == 1){
-        char *old_tz = set_tz("UTC");
-	t = mktime(&stm);
-	unset_tz(old_tz);
-    } else {
-	t = mktime(&stm);
-    }
+    t = make_time(&stm, 0);
 
     return t;
 
@@ -269,10 +333,7 @@
     stm.tm_year = tt.year-1900;
     stm.tm_isdst = -1;
 
-    /* Set TZ to UTC and use mktime to convert to a time_t. */
-    old_tz = set_tz ("UTC");
-    t = mktime (&stm);
-    unset_tz (old_tz);
+    t = make_time(&stm, 0);
 
     return t;
 }
