--- moon.c.old	Fri May 14 04:55:39 2004
+++ moon.c	Thu Jul 22 17:26:25 2004
@@ -44,7 +44,7 @@
 #include "wmgeneral/wmgeneral-x11.h"
 
 static double fpart(double t){
-    return t-trunc(t);
+    return rint(t);
 }
 
 double calc_moon(int month, int day, int year, int hm){
