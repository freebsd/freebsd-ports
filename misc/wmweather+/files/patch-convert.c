--- convert.c.orig	Sun Sep 22 22:00:53 2002
+++ convert.c	Fri Nov  5 22:19:11 2004
@@ -18,6 +18,12 @@
 */
 
 #include <math.h>
+
+#include <sys/param.h>
+#if (__FreeBSD_version < 500000)
+#define NAN (0.0/0.0)
+#endif
+
 #if TM_IN_SYS_TIME
 # if TIME_WITH_SYS_TIME
 #  include <sys/time.h>
@@ -52,7 +58,11 @@
     if(temp_C==999 || dewpt_C==999) return 999;
 
     f=1782.75*(dewpt_C-temp_C)/((237.7+dewpt_C)*(237.7+temp_C));
+#   if (__FreeBSD_version < 500000)
+    return floor(pow(10, f+2)+0.5);
+#   else
     return round(pow(10, f+2));
+#   endif
 }
 
 int rh_F(int temp_F, int dewpt_F){
@@ -61,7 +71,11 @@
     if(temp_F==999 || dewpt_F==999) return 999;
 
     f=3208.95*(dewpt_F-temp_F)/((395.86+dewpt_F)*(395.86+temp_F));
+#   if (__FreeBSD_version < 500000)
+    return floor(pow(10, f+2)+0.5);
+#   else
     return round(pow(10, f+2));
+#   endif
 }
 
 int heatindex_C(int temp_C, int rh){
@@ -75,7 +89,11 @@
 
     temp2=temp_C*temp_C;
     rh2=rh*rh;
+#   if (__FreeBSD_version < 500000)
+    return floor(16.18754948 + 2.900509394*temp_C - 0.0221545692*temp2 + 4.20938791*rh - 0.26300889*temp_C*rh + 0.0039811176*temp2*rh - 0.02956469*rh2 + 0.001305828*temp_C*rh2 - 6.4476e-06*temp2*rh2+0.5);
+#   else
     return round(16.18754948 + 2.900509394*temp_C - 0.0221545692*temp2 + 4.20938791*rh - 0.26300889*temp_C*rh + 0.0039811176*temp2*rh - 0.02956469*rh2 + 0.001305828*temp_C*rh2 - 6.4476e-06*temp2*rh2);
+#   endif
 #endif
 }
 
@@ -88,9 +106,17 @@
     temp3=temp2*temp_F;
     rh2=rh*rh;
     rh3=rh2*rh;
+#   if (__FreeBSD_version < 500000)
+    return floor(16.923 + .185212*temp_F + 5.37941*rh - .100254*temp_F*rh + (9.41695e-3)*temp2 + (7.28898e-3)*rh2 + (3.45372e-4)*temp2*rh - (8.14971e-4)*temp_F*rh2 + (1.02102e-5)*temp2*rh2 - (3.8646e-5)*temp3 + (2.91583e-5)*rh3 + (1.42721e-6)*temp3*rh + (1.97483e-7)*temp_F*rh3 - (2.18429e-8)*temp3*rh2 + (8.43296e-10)*temp2*rh3 - (4.81975e-11)*temp3*rh3+0.5);
+#   else
     return round(16.923 + .185212*temp_F + 5.37941*rh - .100254*temp_F*rh + (9.41695e-3)*temp2 + (7.28898e-3)*rh2 + (3.45372e-4)*temp2*rh - (8.14971e-4)*temp_F*rh2 + (1.02102e-5)*temp2*rh2 - (3.8646e-5)*temp3 + (2.91583e-5)*rh3 + (1.42721e-6)*temp3*rh + (1.97483e-7)*temp_F*rh3 - (2.18429e-8)*temp3*rh2 + (8.43296e-10)*temp2*rh3 - (4.81975e-11)*temp3*rh3);
+#   endif
 #if 0
+#   if (__FreeBSD_version < 500000)
+    return floor(-42.379 + 2.04901523*temp_F + 10.14333127*rh - 0.22475541*temp_F*rh - .00683783*temp2 - .05481717*rh2 + .00122874*temp2*rh + .00085282*temp_F*rh2 - .00000199*temp2*rh2+0.5);
+#   else
     return round(-42.379 + 2.04901523*temp_F + 10.14333127*rh - 0.22475541*temp_F*rh - .00683783*temp2 - .05481717*rh2 + .00122874*temp2*rh + .00085282*temp_F*rh2 - .00000199*temp2*rh2);
+#   endif
 #endif
 }
 
@@ -106,14 +132,22 @@
 
     ret=35.74 + 0.6215*temp_F + (-35.75 + 0.4275*temp_F)*pow(windspeed*50292/57875.0, 0.16);
     if(ret>temp_F) return temp_F;
+#   if (__FreeBSD_version < 500000)
+    return floor(ret+0.5);
+#   else
     return round(ret);
+#   endif
 }
 
 /* Length Conversions */
 
 int in2cm(int in){
     if(in<0) return in;
+#   if (__FreeBSD_version < 500000)
+    return floor(in*2.54+0.5);
+#   else
     return round(in*2.54);
+#   endif
 }
 
 float m2mi(int meters){
@@ -125,27 +159,47 @@
 
 int knots2mph(int knots){
     if(knots<0) return knots;
+#   if (__FreeBSD_version < 500000)
+    return floor(knots*57875/50292.0+0.5);
+#   else
     return round(knots*57875/50292.0);
+#   endif
 }
 
 int knots2kph(int knots){
     if(knots<0) return knots;
+#   if (__FreeBSD_version < 500000)
+    return floor(knots*463/250.0+0.5);
+#   else
     return round(knots*463/250.0);
+#   endif
 }
 
 int kph2knots(int kph){
     if(kph<0) return kph;
+#   if (__FreeBSD_version < 500000)
+    return floor(kph*250/463.0+0.5);
+#   else
     return round(kph*250/463.0);
+#   endif
 }
 
 int knots2mps(int knots){
     if(knots<0) return knots;
+#   if (__FreeBSD_version < 500000)
+    return floor(knots*463/900.0+0.5);
+#   else
     return round(knots*463/900.0);
+#   endif
 }
 
 int mps2knots(int mps){
     if(mps<0) return mps;
+#   if (__FreeBSD_version < 500000)
+    return floor(mps*900/463.0+0.5);
+#   else
     return round(mps*900/463.0);
+#   endif
 }
 
 int knots2beaufort(int knots){
@@ -170,12 +224,20 @@
 
 int temp_C2F(int temp_C){
     if(temp_C==999) return 999;
+#   if (__FreeBSD_version < 500000)
+    return floor(temp_C*9/5.0+32+0.5);
+#   else
     return round(temp_C*9/5.0+32);
+#   endif
 }
 
 int temp_F2C(int temp_F){
     if(temp_F==999) return 999;
+#   if (__FreeBSD_version < 500000)
+    return floor((temp_F-32)*5/9.0+0.5);
+#   else
     return round((temp_F-32)*5/9.0);
+#   endif
 }
 
 
