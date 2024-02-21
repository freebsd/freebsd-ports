--- src/walsh/square-wave-transform.cc.orig	2023-12-24 11:20:28 UTC
+++ src/walsh/square-wave-transform.cc
@@ -44,7 +44,7 @@ void
 swt_normalize(double *f, ulong n)
 // Normalization for the square wave transform.
 {
-    constexpr double s2 = sqrt(0.5);
+    double s2 = sqrt(0.5);
     if ( n <= 2 )
     {
         if ( n == 2 )
