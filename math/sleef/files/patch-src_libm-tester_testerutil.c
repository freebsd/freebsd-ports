--- src/libm-tester/testerutil.c.orig	2021-11-18 16:26:40 UTC
+++ src/libm-tester/testerutil.c
@@ -45,7 +45,7 @@ int isMinusZero(double x) { return x == 0 && copysign(
 double sign(double d) { return d < 0 ? -1 : 1; }
 int xisnan(double x) { return x != x; }
 
-int isnumberf(float x) { return !isinff(x) && !isnanf(x); }
+int isnumberf(float x) { return !isinf(x) && !isnanf(x); }
 int isPlusZerof(float x) { return x == 0 && copysignf(1, x) == 1; }
 int isMinusZerof(float x) { return x == 0 && copysignf(1, x) == -1; }
 float signf(float d) { return d < 0 ? -1 : 1; }
