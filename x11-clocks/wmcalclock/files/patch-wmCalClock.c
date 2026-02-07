--- wmCalClock.c.orig	2002-10-06 07:51:10 UTC
+++ wmCalClock.c
@@ -330,7 +330,7 @@ int main(int argc, char *argv[]) {
     int			i, n, wid, extrady, extradx;
     int 		Year, Month, DayOfWeek, DayOfMonth, OldDayOfMonth;
     int			Hours, Mins, Secs, OldSecs, digit, xoff, D[10], xsize;
-    long		CurrentLocalTime;
+    time_t		CurrentLocalTime;
     double		UT, TU, TU2, TU3, T0, gmst, jd(), hour24();
 
 
