--- moon.c.orig	Fri May 14 04:55:39 2004
+++ moon.c	Fri Nov  5 21:28:09 2004
@@ -20,6 +20,7 @@
 /* One-line algorithm from http://www.moonstick.com/moon_phase_emergency.htm
  * It's a bit rough, but it works well enough */
 
+#include <sys/param.h>
 #if TM_IN_SYS_TIME
 # if TIME_WITH_SYS_TIME
 #  include <sys/time.h>
@@ -44,7 +45,12 @@
 #include "wmgeneral/wmgeneral-x11.h"
 
 static double fpart(double t){
-    return t-trunc(t);
+#  if (__FreeBSD_version < 500000)
+   double integral;
+   return modf(t, &integral);
+#  else
+   return t-trunc(t);
+#  endif
 }
 
 double calc_moon(int month, int day, int year, int hm){
