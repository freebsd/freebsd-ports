--- convert.h.orig	Fri Sep  6 04:04:06 2002
+++ convert.h	Fri Apr 11 02:07:44 2003
@@ -12,6 +12,8 @@
  *   x<0 is used for rh, pressure, and windspeed
  */
 
+#define NAN 0/0
+
 /* Calculations */
 int rh_C(int temp_C, int dewpt_C);
 int rh_F(int temp_F, int dewpt_F);
