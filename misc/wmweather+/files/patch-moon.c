--- moon.c.orig	Sun Sep 22 22:00:53 2002
+++ moon.c	Fri Apr 11 02:07:44 2003
@@ -44,7 +44,7 @@
 #include "wmgeneral/wmgeneral-x11.h"
 
 static double fpart(double t){
-    return t-trunc(t);
+    return rint(t);
 }
 
 double calc_moon(int month, int day, int year, int hm){
