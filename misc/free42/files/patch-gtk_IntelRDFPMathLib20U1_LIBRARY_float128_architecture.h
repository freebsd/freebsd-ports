--- gtk/IntelRDFPMathLib20U1/LIBRARY/float128/architecture.h.orig	2018-07-12 01:32:53 UTC
+++ gtk/IntelRDFPMathLib20U1/LIBRARY/float128/architecture.h
@@ -364,7 +364,7 @@
 
 
 
-#elif (defined(_M_IX86) || defined(ix86) || defined(IX86) || defined(ia32) )
+#elif (defined(_M_IX86) || defined(ix86) || defined(IX86) || defined(ia32) || defined(__i386__))
 
 #	undef  vax
 #	undef  mips
