--- convert.c.orig	Sun Sep 22 22:00:53 2002
+++ convert.c	Thu Jul 22 19:04:18 2004
@@ -18,6 +18,9 @@
 */
 
 #include <math.h>
+#ifndef NAN
+#define NAN (0.0/0.0)
+#endif
 #if TM_IN_SYS_TIME
 # if TIME_WITH_SYS_TIME
 #  include <sys/time.h>
@@ -52,7 +55,7 @@
     if(temp_C==999 || dewpt_C==999) return 999;
 
     f=1782.75*(dewpt_C-temp_C)/((237.7+dewpt_C)*(237.7+temp_C));
-    return round(pow(10, f+2));
+    return rint(pow(10, f+2));
 }
 
 int rh_F(int temp_F, int dewpt_F){
@@ -61,7 +64,7 @@
     if(temp_F==999 || dewpt_F==999) return 999;
 
     f=3208.95*(dewpt_F-temp_F)/((395.86+dewpt_F)*(395.86+temp_F));
-    return round(pow(10, f+2));
+    return rint(pow(10, f+2));
 }
 
 int heatindex_C(int temp_C, int rh){
@@ -75,7 +78,7 @@
 
     temp2=temp_C*temp_C;
     rh2=rh*rh;
-    return round(16.18754948 + 2.900509394*temp_C - 0.0221545692*temp2 + 4.20938791*rh - 0.26300889*temp_C*rh + 0.0039811176*temp2*rh - 0.02956469*rh2 + 0.001305828*temp_C*rh2 - 6.4476e-06*temp2*rh2);
+    return rint(16.18754948 + 2.900509394*temp_C - 0.0221545692*temp2 + 4.20938791*rh - 0.26300889*temp_C*rh + 0.0039811176*temp2*rh - 0.02956469*rh2 + 0.001305828*temp_C*rh2 - 6.4476e-06*temp2*rh2);
 #endif
 }
 
@@ -88,9 +91,9 @@
     temp3=temp2*temp_F;
     rh2=rh*rh;
     rh3=rh2*rh;
-    return round(16.923 + .185212*temp_F + 5.37941*rh - .100254*temp_F*rh + (9.41695e-3)*temp2 + (7.28898e-3)*rh2 + (3.45372e-4)*temp2*rh - (8.14971e-4)*temp_F*rh2 + (1.02102e-5)*temp2*rh2 - (3.8646e-5)*temp3 + (2.91583e-5)*rh3 + (1.42721e-6)*temp3*rh + (1.97483e-7)*temp_F*rh3 - (2.18429e-8)*temp3*rh2 + (8.43296e-10)*temp2*rh3 - (4.81975e-11)*temp3*rh3);
+    return rint(16.923 + .185212*temp_F + 5.37941*rh - .100254*temp_F*rh + (9.41695e-3)*temp2 + (7.28898e-3)*rh2 + (3.45372e-4)*temp2*rh - (8.14971e-4)*temp_F*rh2 + (1.02102e-5)*temp2*rh2 - (3.8646e-5)*temp3 + (2.91583e-5)*rh3 + (1.42721e-6)*temp3*rh + (1.97483e-7)*temp_F*rh3 - (2.18429e-8)*temp3*rh2 + (8.43296e-10)*temp2*rh3 - (4.81975e-11)*temp3*rh3);
 #if 0
-    return round(-42.379 + 2.04901523*temp_F + 10.14333127*rh - 0.22475541*temp_F*rh - .00683783*temp2 - .05481717*rh2 + .00122874*temp2*rh + .00085282*temp_F*rh2 - .00000199*temp2*rh2);
+    return rint(-42.379 + 2.04901523*temp_F + 10.14333127*rh - 0.22475541*temp_F*rh - .00683783*temp2 - .05481717*rh2 + .00122874*temp2*rh + .00085282*temp_F*rh2 - .00000199*temp2*rh2);
 #endif
 }
 
@@ -106,14 +109,14 @@
 
     ret=35.74 + 0.6215*temp_F + (-35.75 + 0.4275*temp_F)*pow(windspeed*50292/57875.0, 0.16);
     if(ret>temp_F) return temp_F;
-    return round(ret);
+    return rint(ret);
 }
 
 /* Length Conversions */
 
 int in2cm(int in){
     if(in<0) return in;
-    return round(in*2.54);
+    return rint(in*2.54);
 }
 
 float m2mi(int meters){
@@ -125,27 +128,27 @@
 
 int knots2mph(int knots){
     if(knots<0) return knots;
-    return round(knots*57875/50292.0);
+    return rint(knots*57875/50292.0);
 }
 
 int knots2kph(int knots){
     if(knots<0) return knots;
-    return round(knots*463/250.0);
+    return rint(knots*463/250.0);
 }
 
 int kph2knots(int kph){
     if(kph<0) return kph;
-    return round(kph*250/463.0);
+    return rint(kph*250/463.0);
 }
 
 int knots2mps(int knots){
     if(knots<0) return knots;
-    return round(knots*463/900.0);
+    return rint(knots*463/900.0);
 }
 
 int mps2knots(int mps){
     if(mps<0) return mps;
-    return round(mps*900/463.0);
+    return rint(mps*900/463.0);
 }
 
 int knots2beaufort(int knots){
@@ -170,12 +173,12 @@
 
 int temp_C2F(int temp_C){
     if(temp_C==999) return 999;
-    return round(temp_C*9/5.0+32);
+    return rint(temp_C*9/5.0+32);
 }
 
 int temp_F2C(int temp_F){
     if(temp_F==999) return 999;
-    return round((temp_F-32)*5/9.0);
+    return rint((temp_F-32)*5/9.0);
 }
 
 
