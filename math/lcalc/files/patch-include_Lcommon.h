--- include/Lcommon.h.orig	2020-03-29 15:43:34 UTC
+++ include/Lcommon.h
@@ -1,3 +1,4 @@
+// Patches borrowed from SageMath.
 // When MPFR is enabled and double is passed to a templated function
 // The function should use precise(ttype) to make sure calculations run
 // within the more precise type
@@ -48,7 +49,7 @@ const bool outputSeries=true;	  // Whether to output t
 
 // Loop i from m to n
 // Useful in tidying up most for loops
-#define loop(i,m,n) for(typeof(m) i=(m); i!=(n); i++)
+#define loop(i,m,n) for(auto i=(m); i!=(n); i++)
 
 // A class for calculations involving polynomials of small degree
 // Not efficient enough for huge polynomials
