--- general.c.orig	2002-04-27 22:33:57.000000000 +0400
+++ general.c	2012-02-26 11:13:09.000000000 +0400
@@ -900,14 +900,32 @@
 
 /* Return a string containing the given time zone, given as a real value     */
 /* having the hours before GMT in the integer part and minutes fractionally. */
+/* Seconds are printed when needed.                                          */
 
 byte *SzZone(zon)
 real zon;
 {
-  static byte szZon[7];
+  static byte szZon[10];
+  int hr, min, sec;
+  real rMin;
 
-  sprintf(szZon, "%c%d:%02d", zon > 0.0 ? '-' : '+', (int)RAbs(zon),
-    (int)(RFract(RAbs(zon))*100.0+rRound/60.0));
+  hr = NFloor(RAbs(zon));
+  rMin = RFract(RAbs(zon)) * 100.0;
+  min = (int)(rMin + rRound / 600.0);
+  rFractal = RFract(rMin);
+  if (rFractal > rOne)
+    rFractal = rSmall;
+  sec = (int)(60.0*rFractal + rRound);
+  while (min >= 60) {
+    min -= 60;
+    hr++;
+  }
+  while (hr >= 24)
+    hr -= 24;
+  if (sec == 0)
+    sprintf(szZon, "%c%d:%02d", zon > 0.0 ? '-' : '+', hr, min);
+  else
+    sprintf(szZon, "%c%d:%02d:%02d", zon > 0.0 ? '-' : '+', hr, min, sec);
   return szZon;
 }
 
@@ -970,7 +988,7 @@
 int *mon, *day, *yea;
 real *tim, zon;
 {
-  dword curtimer;
+  time_t curtimer;
   int min, sec;
   real hr;
 
